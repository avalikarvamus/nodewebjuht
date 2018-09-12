const char PAGE_microajax_js[] PROGMEM = R"=====(
  $( "#ledon" ).click( function () {
  $.get( "/ajax/ledon", function( data ) {
    $( "#result" ).html( data );
  });}
);

$( "#ledoff" ).click(function() {
  $.get( "/ajax/ledoff", function( data ) {
    $( "#result" ).html( data );
  });
});

$( "#left" ).click(function() {
  $.get( "/ajax/left", function( data ) {
    $( "#result" ).html( data );
  });
});

$( "#right" ).click(function() {
  $.get( "/ajax/right", function( data ) {
    $( "#result" ).html( data );
  });
});

$( "#start" ).click(function() {
  $.get( "/ajax/start", function( data ) {
    $( "#result" ).html( data );
  });
});

$( "#stop" ).click(function() {
  $.get( "/ajax/stop", function( data ) {
    $( "#result" ).html( data );
  });
});
)=====";
