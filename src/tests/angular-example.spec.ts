import { TestBed } from '@angular/core/testing'
import { UiCollectionviewSeanComponent } from '../app/ui-collectionview-demo/ui-collectionview-sean.component'
import { Page } from '@nativescript/core'
import 'zone.js';

describe('search.component', () => {
  beforeEach(async () => {
    console.log('hitting beforeEach')
    await TestBed.configureTestingModule({
      declarations: [UiCollectionviewSeanComponent],
      providers: [Page],
    }).compileComponents()
    console.log('hitting after compileComponents')
  })

  it('should fail', async () => {
    console.log('hitting should fail')
    const fixture = TestBed.createComponent(UiCollectionviewSeanComponent)
    const component = fixture.componentInstance as UiCollectionviewSeanComponent
    expect(component.addPlayers(10)).not.toBeTruthy();
  })

  it('should succeed', async () => {
    console.log('hitting should succeed')
    const fixture = TestBed.createComponent(UiCollectionviewSeanComponent)
    const component = fixture.componentInstance as UiCollectionviewSeanComponent
    expect(component.addPlayers(10)).toBeTruthy()
  })
})