import { ComponentFixture, TestBed } from "@angular/core/testing";
import { CollectionViewModule } from "@nativescript-community/ui-collectionview/angular";
import { Page } from "@nativescript/core";
import { UiCollectionviewSeanComponent } from "~/app/ui-collectionview-demo/ui-collectionview-sean.component";
describe("search.component", () => {
    let component: UiCollectionviewSeanComponent;
    let fixture: ComponentFixture<UiCollectionviewSeanComponent>;
  
    beforeEach(async () => {
        await TestBed.configureTestingModule({
            declarations: [UiCollectionviewSeanComponent],
            providers: [Page],
            imports: [CollectionViewModule]
        }).compileComponents();
    });

    beforeEach(() => {
        fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
        component = <UiCollectionviewSeanComponent>fixture.componentInstance;
    });

    it("should be true", async () => {
        expect(component.setTest()).toBeTrue();
    });

    it("should be false", async () => {
        expect(component.setTest()).not.toBeFalse();
    });
});
