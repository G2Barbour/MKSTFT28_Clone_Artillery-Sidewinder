BE CAUTIOUS USING "Download All Files" AS THE THINGIVERSE SERVER IS SLOW TO REFRESH AND YOU MAY GET OLDER FILES WITH ISSUES!

You should be able to get the correct mkstft28_g2_v1.3.5.zip revision using the "Thing Files" button. The correct mkstft28.bin file inside will be dated 4/1-2020 at 4:09PM EST.

Artillery Sidewinder TFT firmware G2 Beta v1.3.x. This is a beta release, alpha release will be 1.4.0 and will be the designation once it is established that everything is running smoothly. I strongly urge you to comment here if you download one of the beta versions, so I can notify you when a bug is found.

Just unzip mkstft28_g2_v1.3.x.zip directly to an SD card, put it in the printer, and reset. 

Also included is v3 of a lightweight ribbon cable support for use with and without an extra 10 conductor rainbow ribbon cable. Original bolts and a zip tie are all that is needed. I also posted it separately, but Thingiverse wanted an stl file so you get it here...

This is adapted from one of the many BigTreeTech msktft28 TFT firmware variants out there. The origination of this code is the mkstft28_v1.0 Clone version made for the Genius by Darkspr1te. You can find it here:
https://codeload.github.com/Blueforcer/MKSTFT_Marlin_Touch/zip/0.0.2

Included in this package is my modified version of that source code titled: MKSTFT_Marlin_RELEASE-0.0.2-1.3.x.zip

A few things to look out for:

There is a bug where it is possible to freeze the display when navigating back and forth between the circular menus between move/heat /extrude.

The disconnect feature does not always work on the first try. Unfortunately my printer/computer have had a connection issue since day 1 where I have to make multiple attempts whether I'm using Octoprint or flashing the Marlin firmware, so my setup is not a good candidate for troubleshooting this function. After a few tries it has been working for me. If someone who can code and has a good working printer and computer wants to try, I have shared the source code. All help is welcome!

1.3.5 Ozollo has joined the project and fixed his first bug: M500 added for PID autotune. Prior to version 1.3.5 the PID autotune features in the Custom menu did not autosave. As of this moment the only known bugs are that disconnect may not be a first time go and that it is possible to freeze the display when navigating back and forth between the circular menus between move/heat/extrude. Menu ordering will be evaluated to accomodate circular menu function.

1.3.4 Prior to version 1.3.4, there was a bug in the cancel print function that would throw a Halt! Printer Stopped error. cancel_print_gcode modified.

1.3.3 Prior to version 1.3.3, the icons were designated to the wrong folder for uploading, so if you weren't already using the unified icon set you would have garbled icons.

1.3.2 Prior to version 1.3.2 there was a bug that would crash the extruder into a print taller than 50mm at the end code. I caught it almost immediately, but this was available for a few hours, so if you were one of the first to download, you'll definitely want to get a newer version. 


Features: 
This version is configured for the build volume of the Sidewinder. 
PID tuning is incorporated for both the bed and extruder with autosave. 
Live flow/speed/temperature adjust and babystepping. 
Filament runout sensor is enabled! 
GCode console interface (accessed by touching the "Info" box on the main status screen or looking for the GCode menu). 
It is enabled for both manual leveling and BL Touch (if you have that enabled in your Marlin firmware). 
The center leveling point has been added, and the corner leveling points are positioned above the mounting points instead of at the far corners. 
There is a disconnect feature so you can flash without unplugging the TFT cable (thought this feature is glitchy as noted above). 
Custom GCode is added to raise the z axis by 100, lower the z axis to 10, present bed to position Y250 for part bed cleaning/part removal, and extrude 100mm of filament. 
Some of the menus are made more circular so it is easier to get between preheating, moving, and extruding. 
There are presets to preheat PLA, ABS, PETG, with option to toggle the bed/nozzle/both as well as a quick button to preheat the bed to 65. 
Magic numbers are hard coded into all touchscreen axis moves (0.12 and 0.04mm instead of 0.10 and 0.01 respectively). 
Percentage progress bar and z axis position are displayed during print.
The bed presents itself to position Y250 upon canceling of the print for bed cleaning/part removal.

Future features goals include:
Adjusting motor steps with a dedicated menu, 
display of M503 parameters, 
graphic display of bed leveling data, 
scrolling for long file names, 
mkstft.txt configuration support, 
and displaying the hotend and bed temperatures while navigating all of the menus.

If you have any problems or suggestions, or if you want to help code or make new icons, let me know.