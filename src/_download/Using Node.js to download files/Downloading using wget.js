// Function to download file using wget
var download_file_wget = function(file_url) {

  // extract the file name
  var file_name = url.parse(file_url).pathname.split('/').pop();
  // compose the wget command
  var wget = 'wget -P ' + DOWNLOAD_DIR + ' ' + file_url;
  // excute wget using child_process' exec function

  var child = exec(wget, function(err, stdout, stderr) {
      if (err) throw err;
      else console.log(file_name + ' downloaded to ' + DOWNLOAD_DIR);
  });
};