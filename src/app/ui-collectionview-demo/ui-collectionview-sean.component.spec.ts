import { Device } from "@nativescript/core";
import { ComponentFixture, TestBed, waitForAsync } from '@angular/core/testing';
import { UiCollectionviewSeanComponent } from './ui-collectionview-sean.component';

import 'zone.js';
import 'zone.js/testing';

describe('UiCollectionviewSeanComponent', () => {
    let component: UiCollectionviewSeanComponent;
    let fixture: ComponentFixture<UiCollectionviewSeanComponent>;
  
    beforeEach(waitForAsync(() => {
      TestBed.configureTestingModule({
        declarations: [ UiCollectionviewSeanComponent ]
      }).compileComponents();
    }));

    console.log('sdk version', Device.sdkVersion);
    it("should use > 16 SDK", function() {
    expect(Device.sdkVersion).toBeGreaterThan(16);
    });
});

