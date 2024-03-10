import { ChangeDetectionStrategy, ChangeDetectorRef, Component, ElementRef, NgZone, OnInit, ViewChild } from '@angular/core';
import { ItemService } from '../item/item.service';
import { ItemVM } from '../item/item';
import { isAndroid } from "@nativescript/core/platform";
import { CollectionView } from '@nativescript-community/ui-collectionview';
import { TableSortType } from '../enums/table-sort-type';
import { EventData, Image, ObservableArray, ScrollEventData, ScrollView } from '@nativescript/core';
import * as stringConstants from "./ui-collectionview-sean.component.strings";


@Component({
	selector: 'ui-collectionview-sean',
	templateUrl: 'ui-collectionview-sean.component.html',
  styleUrls: ['./ui-collectionview-sean.component.scss'],
  changeDetection: ChangeDetectionStrategy.OnPush
})
export class UiCollectionviewSeanComponent implements OnInit {

  readonly id: string = stringConstants.id;
  readonly name: string = stringConstants.name;
  readonly position: string = stringConstants.position;
  readonly height: string = stringConstants.height;
  readonly dateOfBirth: string = stringConstants.dateOfBirth;
  readonly nationality: string = stringConstants.nationality;
  readonly appearances: string = stringConstants.appearances;
  readonly goals: string = stringConstants.goals;
  readonly assists: string = stringConstants.assists;

  readonly generatePlayers: string = stringConstants.generatePlayers;

  isAndroid: boolean = false;

  sortArrow: Image;
  @ViewChild('sortArrow') set SortArrowContent(sortArrowRef: ElementRef) {
    if(sortArrowRef) {
      this.sortArrow = <Image>sortArrowRef.nativeElement;
    }
  }

  idsCollectionView: CollectionView;
  @ViewChild('ids') set idsColumnsContent( idsColumn: ElementRef) {
    if(idsColumn) {
      this.idsCollectionView = <CollectionView>idsColumn.nativeElement;
    }
  };

  mainCollectionView: CollectionView;
  @ViewChild('main') set mainColumnsContent( mainColumn: ElementRef) {
    if(mainColumn) {
      this.mainCollectionView = <CollectionView>mainColumn.nativeElement;
    }
  };

  tableMainBodyScrollView: ScrollView;
  @ViewChild('tableMainBody') set tableMainBodyContent( tableMainBody: ElementRef) {
    if(tableMainBody) {
      this.tableMainBodyScrollView = <ScrollView>tableMainBody.nativeElement;
    }
  };
  tableMainHeadingsScrollView: ScrollView;
  @ViewChild('tableMainHeadings') set mainHeadingsContent( tableMainHeadings: ElementRef) {
    if(tableMainHeadings) {
      this.tableMainHeadingsScrollView = <ScrollView>tableMainHeadings.nativeElement;
    }
  };


  constructor(
    public itemService: ItemService,
    private ngZone: NgZone,
    private changeDetectionRef: ChangeDetectorRef
  ) {
    if(isAndroid) {
      this.isAndroid = true;
    }
  }

  itemsOnScreen: ObservableArray<ItemVM> = new ObservableArray();

  // eslint-disable-next-line @typescript-eslint/no-inferrable-types
  scrollOffsetX: number = 0;
  // eslint-disable-next-line @typescript-eslint/no-inferrable-types
  rowsDisplayed: number = 20;

  columnSorting: Map<string, number> = new Map<string, number>([
    ['ID', TableSortType.Ascending],
    ['Name', TableSortType.Default],
    ['Position', TableSortType.Default],
    ['Height', TableSortType.Default],
    ['Nationality', TableSortType.Default],
    ['Date of Birth', TableSortType.Default],
    ['Goals', TableSortType.Default],
    ['Assists', TableSortType.Default]
  ]);

  ngOnInit() {
    this.itemsOnScreen.splice(0, this.itemsOnScreen.length, ...this.itemService.items.slice(0, this.rowsDisplayed));
    this.changeDetectionRef.detectChanges();
    this.rowsDisplayed = 277;
    this.ngZone.runOutsideAngular(() => {
      this.itemsOnScreen.splice(0, this.itemService.items.length, ...(this.itemService.items.slice(0, this.rowsDisplayed)));
      this.ngZone.run(() => {
        this.changeDetectionRef.markForCheck();
      });
    });
  }

  setVerticalOffsetsToZero(): void {
    this.idsCollectionView.scrollToOffset(0, false);
    this.mainCollectionView.scrollToOffset(0, false);
  }

  sortTableById(): void {

    switch (this.columnSorting.get('ID')) {
      case TableSortType.Default:
      case TableSortType.Descending:
        this.columnSorting.set('ID', TableSortType.Ascending);
        this.itemService.items.sort((a, b) => a.id - b.id);
        this.sortArrow.src = '~/assets/sort_ascending.png';
        break;
      case TableSortType.Ascending:
        this.columnSorting.set('ID', TableSortType.Descending);
        this.itemService.items.sort((a, b) => b.id - a.id);
        this.sortArrow.src = '~/assets/sort_descending.png';
        break;
    }

    this.columnSorting.set('Name', TableSortType.Default);
    this.columnSorting.set('Position', TableSortType.Default);
    this.columnSorting.set('Nationality', TableSortType.Default);
    this.columnSorting.set('Height', TableSortType.Default);
    this.columnSorting.set('Date of Birth', TableSortType.Default);
    this.columnSorting.set('Goals', TableSortType.Default);
    this.columnSorting.set('Assists', TableSortType.Default);

    this.itemsOnScreen.splice(0, this.itemService.items.length, ...(this.itemService.items.slice(0, this.itemService.items.length-1)
        .map(animal => (animal && animal.id !== undefined ? animal : { ...animal, SelectionType: undefined }))));
  }

  loadMoreRows() {
    if (this.rowsDisplayed <= this.itemService.items.length) {
      this.rowsDisplayed = this.rowsDisplayed + 30;
      this.rowsDisplayed = Math.min(this.rowsDisplayed, this.itemService.items.length);
      this.itemsOnScreen.splice(0, this.itemsOnScreen.length, ...this.itemService.items.slice(0, this.rowsDisplayed));
    }
  }

  // eslint-disable-next-line @typescript-eslint/no-inferrable-types
  addPlayers(amount: number = 10) {
    for(let i = 0; i < amount; i++) {
      const newPlayer = this.itemService.generateRandomPlayer();
      this.itemService.items.push(newPlayer);
    }

    // TODO: I'm unsure why, but the sorting is needed to update the view
    switch (this.columnSorting.get('ID')) {
      case TableSortType.Default:
        this.itemService.items.sort((a, b) => b.id - a.id);
        break;
      case TableSortType.Descending:
        this.itemService.items.sort((a, b) => b.id - a.id);
        break;
      case TableSortType.Ascending:
        this.itemService.items.sort((a, b) => a.id - b.id);
        break;
    }

    this.itemsOnScreen.splice(0, this.itemService.items.length, ...(this.itemService.items.slice(0, this.itemService.items.length)
      .map(animal => (animal && animal.id !== undefined ? animal : { ...animal, SelectionType: undefined }))));

    this.changeDetectionRef.detectChanges();
  }

  onScrollVertically(args): void {
    const dyOffset = args.dy;
    const scrollOffsetY = args.scrollOffset;
  
    // The way Android and iOS handle offsetting differs.
    // For that reason, differing values are passed into the function of scrollToOffset
    if (this.isAndroid) {
      this.idsCollectionView.scrollToOffset(dyOffset, false);
      this.mainCollectionView.scrollToOffset(dyOffset, false);
    } else {
      this.idsCollectionView.scrollToOffset(scrollOffsetY, false);
      this.mainCollectionView.scrollToOffset(scrollOffsetY, false);
    }
  };

  // Removes elastic bouncing animation when ScrollView reaches the edges of lists
  doLoadedRemoveBandingAnimation(data: EventData): void {
    const scrollView = <ScrollView>data.object;
    if(global.isAndroid) {
      scrollView.android.setOverScrollMode(android.view.View.OVER_SCROLL_NEVER);
      scrollView.android.setVerticalScrollBarEnabled(false);
      scrollView.android.setHorizontalScrollBarEnabled(false);
      scrollView.android.setScrollBarStyle(android.R.style.Widget_ScrollView);
    } else {
      scrollView.ios.bounces = false;
      scrollView.ios.showsVerticalScrollIndicator = false;
      scrollView.ios.showsHorizontalScrollIndicator = false;
    }
  }

  onScrollHorizontallyHeadings(args: ScrollEventData): void {
    this.scrollOffsetX = args.scrollX;
    this.tableMainBodyScrollView.scrollToHorizontalOffset(this.scrollOffsetX, false);
  }

  onScrollHorizontallyMain(args: ScrollEventData): void {
    this.scrollOffsetX = args.scrollX;
    this.tableMainHeadingsScrollView.scrollToHorizontalOffset(this.scrollOffsetX, false);
  }
}