import { Device } from "@nativescript/core";

// A sample Jasmine test
describe("A suite", function() {
  it("contains spec with an expectation", function() {
    expect(true).toBe(true);
  });
});

describe("iOS Device", function() {
  console.log('sdk version', Device.sdkVersion);
  it("should use > 14 SDK", function() {
    expect(Device.sdkVersion).toBeGreaterThan(14);
  });
});
