import { Device } from "@nativescript/core";

describe("iOS Device", function() {
  it("should use > 14 SDK", function() {
    expect(Device.sdkVersion).toBe('12');
  });
});