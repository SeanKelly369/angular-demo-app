import { TestBed } from '@angular/core/testing'
import { UiCollectionviewSeanComponent } from '../app/ui-collectionview-demo/ui-collectionview-sean.component'
import { Page } from '@nativescript/core'
// import 'zone.js/dist/zone-testing';

describe('search.component', () => {
  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [UiCollectionviewSeanComponent],
      providers: [Page],
    }).compileComponents()
  })

  it('should fail', async () => {
    const fixture = TestBed.createComponent(UiCollectionviewSeanComponent)
    const component = fixture.componentInstance as UiCollectionviewSeanComponent
    expect(component.addPlayers(10)).toBeTruthy()
  })

  it('should succeed', async () => {
    const fixture = TestBed.createComponent(UiCollectionviewSeanComponent)
    const component = fixture.componentInstance as UiCollectionviewSeanComponent
    expect(component.addPlayers(10)).toBeTruthy()
  })
})