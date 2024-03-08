import { Component, OnInit } from '@angular/core'

import { ItemVM } from './item'
import { ItemService } from './item.service'

@Component({
  selector: 'ns-items',
  templateUrl: './items.component.html',
  styleUrls: ['../ui-collectionview-demo/ui-collectionview-sean.component.scss'],

})
export class ItemsComponent implements OnInit {
  items: Array<ItemVM>

  constructor(private itemService: ItemService) {}

  ngOnInit(): void {
    this.items = this.itemService.getItems()
  }
}
