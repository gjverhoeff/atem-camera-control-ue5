## ATEM Camera Remote Control UE5
This is a small program and Unreal Engine 5 plugin to control a virtual camera in UE5 trough the Camera Control Settings of an ATEM. 



### Usage

- Start atem-connect-win.exe, fill in the CameraID you want to use and the IP of the ATEM. 
- Use the ws:// address that is given in the terminal in the Unreal Engine 5 plugin.
- Setup the plugin as in the picture to start receiving data (there is also a small example included in the plugin)
- Within Camera Control settings of the ATEM make sure to pick the "Any Camera Type"


![image info](./Pictures/setup_plugin.png)



### Tested with: 

- ATEM SDI Extreme ISO running 9.5.1
- ATEM Constellation 8K running 9.6.3

  
### Disclaimer and Acknowledgement
This is using atem-connection by Sofie and the atem-connect-win.exe will change in the next version to get the camera settings at startup.
