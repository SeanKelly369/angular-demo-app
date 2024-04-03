import { NgModule } from '@angular/core';
import { Routes } from '@angular/router';
import { NativeScriptRouterModule } from '@nativescript/angular';

import { ItemsComponent } from './item/items.component';
import { ItemDetailComponent } from './item/item-detail.component';

const routes: Routes = [
  { path: '', redirectTo: '/items', pathMatch: 'full' },
  { path: 'items', component: ItemsComponent },
  { path: 'item/:id', component: ItemDetailComponent },
  { path: 'ui-components', loadChildren: () => import('./ui-components/ui-components.module').then(m => m.UiCollectionviewSeanModule) },
  { path: 'ui-collectionview-sean', loadChildren: () => import('./ui-collectionview-demo/ui-collectionview-sean.module').then(m => m.UiCollectionviewSeanModule) }
];

@NgModule({
  imports: [NativeScriptRouterModule.forRoot(routes)],
  exports: [NativeScriptRouterModule]
})
export class AppRoutingModule {}
