import { ChangeDetectionStrategy, Component, OnInit } from "@angular/core";

@Component({
    selector: 'ui-components',
    templateUrl: 'ui-components.component.html',
    styleUrls: ['./ui-components.component.scss'],
    changeDetection: ChangeDetectionStrategy.OnPush
})
export class UiComponentsComponent implements OnInit {
    ngOnInit(): void {
        
    }
    
}