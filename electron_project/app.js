let video
video = window.document.querySelector('video');
  let errorCallback = (error) => {
    console.log(
      'There was an error connecting to the video stream:', error
    );
  };

  navigator.mediaDevices.enumerateDevices().then(devices=>{
	  console.log('devices: ', devices)
  })
  /*
  navigator.mediaDevices.getUserMedia({
  video: {
    deviceId: { exact: camera1Id }
  }
});
   */
  
  window.navigator.webkitGetUserMedia(
    {video: true, audio: false,},
(localMediaStream) => {
    video.src = window.URL.createObjectURL(localMediaStream);
    video.onloadedmetadata = bindSavingPhoto;
  }, errorCallback);

