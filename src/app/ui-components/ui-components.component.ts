import { ChangeDetectionStrategy, Component, ElementRef, ViewChild } from "@angular/core";
import { AbsoluteLayout, Button, Color, CoreTypes, EventData, GestureTypes, StackLayout } from "@nativescript/core";
import { Pair } from "@nativescript/core/ui/animation";

@Component({
    selector: 'ui-components',
    templateUrl: 'ui-components.component.html',
    styleUrls: ['./ui-components.component.scss'],
    changeDetection: ChangeDetectionStrategy.OnPush
})
export class UiComponentsComponent {
    
    constructor() {
        
    }

    readonly whiteColour: Color = new Color('white');
    readonly redColour: Color = new Color('red');
    readonly skyBlueColour: Color = new Color('rgb(116, 174, 209)');
    
    isOn: boolean = false;
    isAbsoluteOn: boolean = false;
    // scaleChange: Pair = Pair(4000, 5444);


    absoluteExample: AbsoluteLayout
    @ViewChild('absoluteExample') set absoluteExampleSet (absoluteExampleRef: ElementRef) {
        if(absoluteExampleRef) {
            this.absoluteExample = <AbsoluteLayout>absoluteExampleRef.nativeElement;
        }
    }

    doubleTap: StackLayout;
    @ViewChild('doubleTap') set doubleTapSet (doubleTapRef: ElementRef) {
        if(doubleTapRef) {
            this.doubleTap = <StackLayout>doubleTapRef.nativeElement;
        }
    }

    stackDemo: StackLayout;
    @ViewChild('stackDemo') set stackDemoSet (stackDemo: ElementRef) {
        if(stackDemo) {
            this.stackDemo = <StackLayout>stackDemo.nativeElement;
        }
    }

    animatedExample: Button;
    @ViewChild('animatedExample') set animatedExampleContent (animatedExampleRef: ElementRef) {
      if(animatedExampleRef) {
        this.animatedExample = <Button>animatedExampleRef.nativeElement;
      }
    }

    absoluteLayoutChange() {

        this.isAbsoluteOn = !this.isAbsoluteOn;
        if(this.isAbsoluteOn) {
            this.absoluteExample.className = 'absoluteOff';
            this.absoluteExample.animate({
                opacity: 0.5,
                duration: 1000,
                translate: <Pair>{x: 5, y: 6},
                scale: <Pair>{x: 1.2, y: 0.8},
                height: 20,
                width: 40,
                delay: 200,
                rotate: 12,
                curve: CoreTypes.AnimationCurve.cubicBezier(0, 3, 0, 6),
                iterations: 2,
            });
            this.absoluteExample.scaleX = 2;

        } else {
            this.absoluteExample.className = 'absoluteOn';
            this.absoluteExample.scaleX = 1;
        }
        this.absoluteExample.translateY = this.absoluteExample.translateY + 20
    }

    onDoubleTapExampleLoaded(args: EventData) {
        console.log(args.eventName);
        console.log(args.object);
        this.doubleTap.on(GestureTypes.doubleTap, (args: EventData) => {
            console.log(args.eventName);
            console.log(args.object);
            this.animatedExample.backgroundColor = this.skyBlueColour;
        });
    }

    onTapEventTwo(): void {
        this.stackDemo.backgroundColor = '#efefef';
        this.stackDemo.opacity = 0.5;
        this.stackDemo.borderColor = '#2312ed';
        this.stackDemo.borderWidth = 2;
        this.stackDemo.height = 66;
        this.stackDemo.boxShadow = '2 2 3 2 rgba(0, 0, 0, 0.5)';
        this.stackDemo.margin = '6 4 6 4';
        this.stackDemo.color = new Color('rgba(255, 0, 0, 0.9)');
        this.stackDemo.style.fontFamily = 'Monospace';
        this.stackDemo.style.fontSize = 20;
        this.stackDemo.rotateY = 60;
        this.stackDemo.translateX = 5;
        this.stackDemo.style.letterSpacing = .4;
    }

    onTapEvent(): void {
        this.animatedExample.style.alignContent = 'center';
        this.animatedExample.style.width = 200;
        if(this.isOn) {
            this.animatedExample.backgroundColor = this.redColour;
            this.animatedExample.color = this.whiteColour;
            this.animatedExample.borderRadius = 5;

            this.animatedExample.animate({ translate: <Pair>{x: 5, y: 6}, duration: 400 });

        } else {
            this.animatedExample.backgroundColor = this.whiteColour;
            this.animatedExample.color = this.redColour;
            this.animatedExample.borderColor = this.redColour;
            this.animatedExample.borderRadius = 5;
            this.animatedExample.borderWidth = 1;
            setTimeout( () => {
                this.animatedExample.animate({ translate: <Pair>{x: 20, y: 25}, duration: 400 });

                
            }, 400);

        }
        this.isOn = !this.isOn;
    }

    onDoubleTap() {

    }
}
function Pair(arg0: number, arg1: number): import("@nativescript/core/ui/animation").Pair {
    throw new Error("Function not implemented.");
}

