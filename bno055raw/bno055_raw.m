% Open the serial port (adjust COM port as needed)
s = serialport("/dev/tty.usbmodem14401",9600);

% Read data from the Arduino
while (true)
    data = readline(s);
    readings = sscanf(data, "%f, %f, %f, %f, %f, %f, %f, %f, %f");

    if numel(readings) == 9
        Accel = readings(1:3); % 3x1 matrix for Accelerometer
        Mag = readings(4:6);   % 3x1 matrix for Magnetometer
        Gyro = readings(7:9);  % 3x1 matrix for Gyroscope

        % Display the data (optional)
        disp('Accel: '); disp(Accel);
        disp('Mag: '); disp(Mag);
        disp('Gyro: '); disp(Gyro);
    end
end
