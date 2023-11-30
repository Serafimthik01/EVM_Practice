using Raven.Iot.Device;
using Raven.Iot.Device.GpioExpander;
using System.Device.I2c;
using Iot.Device.RotaryEncoder;
using System.Device.Gpio;
using UnitsNet;

const int D0 = 24;
const int D1 = 25;
const int D2 = 0;

if (DeviceHelper.GetGpioExpanderDevices() is [I2cConnectionSettings settings])
{
    using GpioExpander gpioExpander = new(settings);

    gpioExpander.Calibrate(Angle.FromDegrees(180), TimeSpan.FromMicroseconds(600), TimeSpan.FromMicroseconds(2600));

    using ScaledQuadratureEncoder encoder = new ScaledQuadratureEncoder(
        pinA: DeviceHelper.WiringPiToBcm(D0),
        pinB: DeviceHelper.WiringPiToBcm(D1),
        PinEventTypes.Falling,
        pulsesPerRotation: 20,
        pulseIncrement: 1,
        rangeMin: 0.0,
        rangeMax: 180.0);

    encoder.Debounce = TimeSpan.FromMilliseconds(2);

    encoder.ValueChanged += (o, e) =>
    {
        gpioExpander.WriteAngle(D2, Angle.FromDegrees(e.Value));
    };

    Console.ReadKey();
}

