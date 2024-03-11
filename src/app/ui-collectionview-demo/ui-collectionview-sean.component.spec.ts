import { ComponentFixture, TestBed, async } from '@angular/core/testing';
import { UiCollectionviewSeanComponent } from './ui-collectionview-sean.component';
import 'zone.js';

describe('UiCollectionviewSeanComponent', () => {
    let component: UiCollectionviewSeanComponent;
    let fixture: ComponentFixture<UiCollectionviewSeanComponent>;

    beforeEach(async(() => {
      TestBed.configureTestingModule({
        declarations: [UiCollectionviewSeanComponent]
      }).compileComponents();

      fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
      component = fixture.componentInstance;
      fixture.detectChanges();
      spyOn(console, "log");
    }));

    it("sanity check", () => {
      expect(component).toBeTruthy();
      expect(component.addPlayers).toBe(
        `hello ${isIOS ? "from ios" : "from android"}`
      );
    });

});
