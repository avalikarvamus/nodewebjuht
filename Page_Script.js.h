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


$( "#uleft" ).click(function() {
  $.get( "/ajax/uleft", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#uright" ).click(function() {
  $.get( "/ajax/uright", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});


$( "#bleft" ).click(function() {
  $.get( "/ajax/bleft", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#bright" ).click(function() {
  $.get( "/ajax/bright", function( data ) {
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

$( "#slow" ).click(function() {
  $.get( "/ajax/slow", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#medium" ).click(function() {
  $.get( "/ajax/medium", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#quick" ).click(function() {
  $.get( "/ajax/quick", function( data ) {
    $( "#result" ).html( data );
    $("#rxConsole").prepend(data+"\n");
  });
});

$( "#back" ).click(function() {
  $.get( "/ajax/back", function( data ) {
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
