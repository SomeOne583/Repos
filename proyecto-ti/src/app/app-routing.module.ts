import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { MainComponent } from './main/main.component';
import { ServicesComponent } from './services/services.component';
import { AboutComponent } from './about/about.component';

const routes: Routes = [
  {
    path: "main", component: MainComponent
  },
  {
    path: "services", component: ServicesComponent
  },
  {
    path: "about", component: AboutComponent
  },
  {
    path: "**", component: MainComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
