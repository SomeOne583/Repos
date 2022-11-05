import { Component, OnInit, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { MatSnackBar } from '@angular/material/snack-bar';
import { MatDialog, MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';

export interface Service {
  id: number,
  name: string,
  cant: number
}

@Component({
  selector: 'app-main',
  templateUrl: './main.component.html',
  styleUrls: ['./main.component.css']
})
export class MainComponent implements OnInit {
  user: object;
  services: Service[];
  dialogRef: MatDialogRef<ServiceDialog>;

  constructor(private http: HttpClient, private _snackBar: MatSnackBar, public dialog: MatDialog) { }

  sign(nombre: string, mail: string) {
    this.user = {
      "mail": mail,
      "name": nombre
    }

    this.http.get<any>(`http://localhost:3000/users?mail=${mail}`, { observe: 'response' })
    .subscribe((resp) => {
      if (resp.body.length != 0) {
        this._snackBar.open("Ya esta registrado este correo", "", { duration: 5000 });
      } else {
        this.http.post<any>("http://localhost:3000/users", this.user, { observe: "response" })
        .subscribe(() => {
          this._snackBar.open("Registrado con éxito", "", { duration: 5000 });
          window.location.reload();
        });
      }
    });
  }

  comprar(name: string) {
    this.dialogRef = this.dialog.open(ServiceDialog, {
      width: "700px",
      data: { service: name, client: "", phone: "", address: "" }
    });

    this.dialogRef.afterClosed()
    .subscribe((result) => {
      if (result != "cancelado") {
        let id, cant: number;
        this.http.get<any>(`http://localhost:3000/services?name=${result['service']}`, { observe: "response"})
        .subscribe((resp) => {
          id = resp.body[0]['id'];
          cant = resp.body[0]['cant'];
          cant++;
          let data = {
            cant: cant
          };
          let order = {
            service: id,
            client: result['client'],
            phone: result['phone'],
            address: result['address']
          };
          this.http.patch<any>(`http://localhost:3000/services/${id}`, data, { observe: "response"})
          .subscribe(() => {
            this._snackBar.open("Orden solicitada", "", { duration: 5000 });
            this.http.post<any>("http://localhost:3000/orders", order, { observe: "response"})
            .subscribe(() => {
              window.location.reload();
            });
          });
        });
      }
    });
  }

  ngOnInit(): void {
    this.http.get<any>("http://localhost:3000/services?_sort=cant&_order=desc&_limit=3", { observe: "response"})
    .subscribe((resp) => {
      this.services = resp.body;
    });
  }

}

@Component({
  selector: 'service-dialog',
  templateUrl: '../service-dialog.html'
})
export class ServiceDialog {
  constructor(
    public dialogRef: MatDialogRef<ServiceDialog>,
    @Inject(MAT_DIALOG_DATA) public data: { service: string, client: string, phone: string, address: string }
  ) {}
}
