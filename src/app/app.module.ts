import { NgModule, NO_ERRORS_SCHEMA } from '@angular/core'
import { NativeScriptModule, NativeScriptRouterModule } from '@nativescript/angular'
import { AppRoutingModule } from './app-routing.module'
import { AppComponent } from './app.component'
import { ItemsComponent } from './item/items.component'
import { ItemDetailComponent } from './item/item-detail.component'
import { CollectionViewModule } from '@nativescript-community/ui-collectionview/angular';

@NgModule({
  bootstrap: [AppComponent],
  imports: [NativeScriptModule, AppRoutingModule, CollectionViewModule, NativeScriptRouterModule.forChild(
      [
        { path: 'ui-collectionview-sean', loadChildren: () => import('./ui-collectionview-demo/ui-collectionview-sean.module').then(m => m.UiCollectionviewSeanModule) },
      ]
    )
  ],
  declarations: [AppComponent, ItemsComponent, ItemDetailComponent],
  providers: [],
  schemas: [NO_ERRORS_SCHEMA],
})
export class AppModule {}
