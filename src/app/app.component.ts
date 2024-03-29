import { Component } from '@angular/core';
import { Application } from "@nativescript/core/application";;
import { Trace as trace } from '@nativescript/core/trace';


@Component({
  selector: 'ns-app',
  templateUrl: './app.component.html',
})
export class AppComponent {

  constructor() {

    Application.on(Application.resumeEvent, () => {
      console.log('resume');
      trace.write(`Application.resumeEvent`, trace.categories.Debug);
    });
  }
}
