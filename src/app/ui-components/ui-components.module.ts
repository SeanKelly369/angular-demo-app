import { NgModule, NO_ERRORS_SCHEMA } from '@angular/core';
import { NativeScriptCommonModule, NativeScriptRouterModule } from '@nativescript/angular';
import { CollectionViewModule } from '@nativescript-community/ui-collectionview/angular';
import { UiComponentsComponent } from '../ui-components/ui-components.component';

@NgModule({
  imports: [NativeScriptCommonModule, CollectionViewModule, NativeScriptRouterModule.forChild(
    [
      { path: '', component: UiComponentsComponent }
    ]
  )],
  declarations: [UiComponentsComponent],
  schemas: [ NO_ERRORS_SCHEMA]
})
export class UiCollectionviewSeanModule {}