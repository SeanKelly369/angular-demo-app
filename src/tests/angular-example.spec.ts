import { TestBed, ComponentFixture, waitForAsync } from '@angular/core/testing';
import { BrowserDynamicTestingModule, platformBrowserDynamicTesting } from '@angular/platform-browser-dynamic/testing';
import { UiCollectionviewSeanComponent } from '../app/ui-collectionview-demo/ui-collectionview-sean.component';
import 'zone.js';
import 'zone.js/testing';

// Initialize the test environment
TestBed.initTestEnvironment(BrowserDynamicTestingModule, platformBrowserDynamicTesting());

describe('UiCollectionviewSeanComponent', () => {
  let component: UiCollectionviewSeanComponent;
  let fixture: ComponentFixture<UiCollectionviewSeanComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({ declarations: [UiCollectionviewSeanComponent] }); // Compile the component template
    fixture = TestBed.createComponent(UiCollectionviewSeanComponent);
    component = fixture.componentInstance;
  });

  it('should create', () => {
    // Check if the component is created successfully
    expect(component).toBeDefined();
  });

  // Add more test cases as needed
});
