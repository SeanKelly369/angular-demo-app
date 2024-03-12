import { TestBed, ComponentFixture, waitForAsync, async, tick } from '@angular/core/testing';
import { BrowserDynamicTestingModule, platformBrowserDynamicTesting } from '@angular/platform-browser-dynamic/testing';
import { UiCollectionviewSeanComponent } from '../app/ui-collectionview-demo/ui-collectionview-sean.component';
import 'zone.js';
import 'zone.js/testing';
import { Device } from '@nativescript/core';

// Initialize the test environment
TestBed.initTestEnvironment(BrowserDynamicTestingModule, platformBrowserDynamicTesting());

describe('UiCollectionviewSeanComponent', () => {
  let component: UiCollectionviewSeanComponent;
  let fixture: ComponentFixture<UiCollectionviewSeanComponent>;

  beforeEach(waitForAsync(async () => {
    await TestBed.configureTestingModule({ 
        providers: [
            UiCollectionviewSeanComponent
        ] 
    }).compileComponents(); // Compile the component template
    }));

    // describe("A suite", function() {
    //     it("contains spec with an expectation", function() {
    //       expect(true).toBe(true);
    //     });
    //   });
      
    //   describe("iOS Device", function() {
    //     console.log('sdk version', Device.sdkVersion);
    //     it("should use > 14 SDK", function() {
    //       expect(Device.sdkVersion).toBeGreaterThan(14);
    //     });
    //   });

    beforeEach(() => {
        fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
        component = fixture.componentInstance;
    });

it('should create', () => {
      fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
      fixture.detectChanges();
      tick(2000);
      fixture.detectChanges();

      component = fixture.debugElement.componentInstance;
    // Check if the component is created successfully
    expect(component).toBeTruthy();
  });

  // Add more test cases as needed
});
