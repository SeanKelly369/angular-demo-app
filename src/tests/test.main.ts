import '@nativescript/core/globals'
import '@nativescript/angular/polyfills'
import '@nativescript/zone-js/dist/pre-zone-polyfills'
import '@nativescript/zone-js'
import { TestBed } from '@angular/core/testing'
import { NativeScriptTestingModule } from '@nativescript/angular/testing'
import { platformBrowserDynamicTesting } from '@angular/platform-browser-dynamic/testing'

TestBed.initTestEnvironment([NativeScriptTestingModule], platformBrowserDynamicTesting())
