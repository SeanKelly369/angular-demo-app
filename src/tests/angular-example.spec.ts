import { ComponentFixture, TestBed } from "@angular/core/testing";
import { Page } from "@nativescript/core";
import { UiCollectionviewSeanComponent } from "~/app/ui-collectionview-demo/ui-collectionview-sean.component";
describe("search.component", () => {
    let component: UiCollectionviewSeanComponent;
    let fixture: ComponentFixture<UiCollectionviewSeanComponent>;
  
    beforeEach(async () => {
        await TestBed.configureTestingModule({
            declarations: [UiCollectionviewSeanComponent],
            providers: [
                Page
            ]
        }).compileComponents();
    });

    beforeEach(() => {
        fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
        component = fixture.componentInstance;
    });

    it("should fail", async () => {
        fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
        component = fixture.componentInstance as UiCollectionviewSeanComponent;
        expect(component.setTest()).toBeTrue();
    });
});
