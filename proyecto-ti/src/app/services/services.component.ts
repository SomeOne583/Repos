import { HttpClient } from '@angular/common/http';
import { Component, Inject, OnInit } from '@angular/core';
import { MatDialog, MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { MatSnackBar } from '@angular/material/snack-bar';

export interface Service {
  id: number,
  name: string,
  cant: number
}

@Component({
  selector: 'app-services',
  templateUrl: './services.component.html',
  styleUrls: ['./services.component.css']
})
export class ServicesComponent implements OnInit {
  services: Service[];
  dialogRef: MatDialogRef<ServiceDialog2>;

  constructor(private http: HttpClient, private _snackBar: MatSnackBar, public dialog: MatDialog) { }

  comprar(name: string) {
    this.dialogRef = this.dialog.open(ServiceDialog2, {
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
            .subscribe(() => {});
          });
        });
      }
    });
  }

  ngOnInit(): void {
    this.http.get<any>("http://localhost:3000/services", { observe: "response"})
    .subscribe((resp) => {
      this.services = resp.body;
    });
  }

}

@Component({
  selector: 'service-dialog',
  templateUrl: '../service-dialog.html'
})
export class ServiceDialog2 {
  constructor(
    public dialogRef: MatDialogRef<ServiceDialog2>,
    @Inject(MAT_DIALOG_DATA) public data: { service: string, client: string, phone: string, address: string }
  ) {}
}
