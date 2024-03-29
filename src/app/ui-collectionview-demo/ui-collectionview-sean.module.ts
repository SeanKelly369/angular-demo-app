import { NgModule, NO_ERRORS_SCHEMA } from '@angular/core';
import { NativeScriptCommonModule, NativeScriptRouterModule } from '@nativescript/angular';
import { CollectionViewModule } from '@nativescript-community/ui-collectionview/angular';
import { UiCollectionviewSeanComponent } from './ui-collectionview-sean.component';
import { UiComponentsComponent } from '../ui-components/ui-components.component';

@NgModule({
  imports: [NativeScriptCommonModule, CollectionViewModule, NativeScriptRouterModule.forChild(
    [
      { path: '', component: UiCollectionviewSeanComponent },
      { path: '', component: UiComponentsComponent }
    ]
  )],
  declarations: [UiCollectionviewSeanComponent],
  schemas: [ NO_ERRORS_SCHEMA]
})
export class UiCollectionviewSeanModule {}