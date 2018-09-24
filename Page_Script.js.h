const char * microajax_js = R"=====(
  $( "#ledon" ).click( function () {
  $.get( "/ajax/ledOn", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });}
);

$( "#ledoff" ).click(function() {
  $.get( "/ajax/ledOff", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#greenled" ).click(function() {
  $.get( "/ajax/led", function( data ) {
    $( "#led" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#left" ).click(function() {
  $.get( "/ajax/left", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#right" ).click(function() {
  $.get( "/ajax/right", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#start" ).click(function() {
  $.get( "/ajax/start", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#stop" ).click(function() {
  $.get( "/ajax/stop", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$(document).ready(function () {
    var interval = 1500;   //number of mili seconds between each call
    var refresh = function() {
      $.ajax({
            url: "/ajax/temp",
            cache: false,
            success: function(data) {
                $('#celsius').html(data);
                $("#celsiusLog").append(", "+data);
                setTimeout(function() {
                    refresh();
                }, interval);
            }
        });
    };
    refresh();
});
)=====";
