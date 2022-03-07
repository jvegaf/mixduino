var Mixduino = {};

Mixduino.debounce = false;

Mixduino.buttons = {
    '[Channel1]': { // an object within another object
        'play': 0x30,
        'cue': 0x32,
        'loop': 0x34
    },
    '[Channel2]': {
        'play': 0x31,
        'cue': 0x33,
        'loop': 0x35
    },
    '[Channel3]': { // an object within another object
        'play': 0x30,
        'cue': 0x32,
        'loop': 0x34
    },
    '[Channel4]': {
        'play': 0x31,
        'cue': 0x33,
        'loop': 0x35
    }
}

Mixduino.leds = {
    'fx1effect1': 0x2A,
    'fx1effect2': 0x2B,
    'fx1effect3': 0x2C,
    'fx2effect1': 0x2D,
    'fx2effect2': 0x2E,
    'fx2effect3': 0x2F
}

Mixduino.rgbLeds = {
    // TODO: CHANGE VALUES
    'deckSelect': 0x0A,
    'rangeLeft': 0x58,
    'syncLeft': 0x58,
    'rangeRight': 0x58,
    'syncRight': 0x58
}

Mixduino.colors = {
    'off': 0x00,
    'blue': 0x01,
    'orange': 0x02,
    'yellow': 0x03,
    'gray': 0x04,
    'green': 0x05,
    'red': 0x06,
    'purple': 0x07
}


Mixduino.init = function () {
    engine.makeConnection('[Channel1]', 'VuMeter', Mixduino.vuCallback);
    engine.makeConnection('[Channel2]', 'VuMeter', Mixduino.vuCallback);
    engine.makeConnection('[Channel4]', 'VuMeter', Mixduino.vuCallback);
    engine.makeConnection('[Master]', 'VuMeterL', Mixduino.vuCallback);
    engine.makeConnection('[Master]', 'VuMeterR', Mixduino.vuCallback);
    Mixduino.initDeck('[Channel1]')
    Mixduino.initDeck('[Channel2]')
}

Mixduino.shutdown = function() {
    // left deck leds
    // midi.sendShortMsg(0x80, 0x28, 0x00); // left sync
    midi.sendShortMsg(0x80, 0x32, 0x00); // left cue
    midi.sendShortMsg(0x80, 0x33, 0x00); // right cue
    midi.sendShortMsg(0x80, 0x30, 0x00); // left play
    midi.sendShortMsg(0x80, 0x31, 0x00); // right play
    midi.sendShortMsg(0x80, 0x27, 0x00); // phones deck a
    midi.sendShortMsg(0x80, 0x28, 0x00); // phones deck b
    midi.sendShortMsg(0x80, 0x29, 0x00); // phones deck c
    midi.sendShortMsg(0x80, 0x34, 0x00); // left loop
    midi.sendShortMsg(0x80, 0x35, 0x00); // right loop

    
    midi.sendShortMsg(0x80, 0x2A, 0x00); // fx1 btn 1
    midi.sendShortMsg(0x80, 0x2B, 0x00); // fx1 btn 2
    midi.sendShortMsg(0x80, 0x2C, 0x00); // fx1 btn 3
    midi.sendShortMsg(0x80, 0x2D, 0x00); // fx2 btn 1
    midi.sendShortMsg(0x80, 0x2E, 0x00); // fx2 btn 2
    midi.sendShortMsg(0x80, 0x2F, 0x00); // fx2 btn 3

    // VU meters    
    midi.sendShortMsg(0xBB, 0x00, 0x00); // VU meter deck a
    midi.sendShortMsg(0xBB, 0x01, 0x00); // VU meter deck b
    midi.sendShortMsg(0xBB, 0x02, 0x00); // VU meter deck c
    midi.sendShortMsg(0xBB, 0x03, 0x00); // VU meter master left
    midi.sendShortMsg(0xBB, 0x04, 0x00); // VU meter master right
}

Mixduino.vuCallback = function(value, group, control) {
    var midiValue = value * 16;
    var midiNumber = 0;

    switch (group) {
        case '[Channel1]':
            break;

        case '[Channel2]':
            midiNumber = 1;
            break;

        case '[Channel4]':
            midiNumber = 2
            break;

        case '[Master]':
            midiNumber = control === 'VuMeterL' ? 3 : 4
            break;

        default:
            break;
    }

    midi.sendShortMsg(0xBB, midiNumber, midiValue )
    }

Mixduino.deck = {
    // a hash table (technically an object) to store which deck each side of the controller is manipulating
    // The keys (object properties) on the left represent the <group> elements in the XML mapping file.
    // The values on the right represent which deck that set of mappings in the XML file is currently controlling.
    // These values are toggled between [Channel1]/[Channel4] and [Channel2]/[Channel4] by the deckToggleButton function below.
    // see https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Object_initializer
    '[Channel1]': '[Channel1]',
    '[Channel2]': '[Channel2]'
}

Mixduino.buttons['[Channel1]'] = Mixduino.buttons['[Channel3]'] // Copy [Channel2] to [Channel4]
Mixduino.buttons['[Channel4]'] = Mixduino.buttons['[Channel2]'] // Copy [Channel2] to [Channel4]

Mixduino.channelRegEx = /\[Channel(\d+)\]/ // a regular expression used in the deckToggleButton function below
// This extracts the number from the strings '[Channel1]' ... '[Channel4]' so we can do math with that number
// see https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/RegExp
Mixduino.deckToggleButton = function (channel, control, value, status, group) {
    if (value) { // only execute the below code when the button is pressed but not when it is released
        // First, get the number out of the string '[Channel1]' ... '[Channel4]'
        var deckNumber = parseInt( // convert string to an integer number variable
                             Mixduino.channelRegEx.exec( // execute the regular expression
                                 Mixduino.deck[group] // on this string
                             )[1] // Get the string that matches the part of the regular expression inside the first group of parentheses in the regular expression
                                  // which is (\d+)
                                  // this matches any number of digits
                          )
        if (deckNumber <= 2) {
            deckNumber += 2 // This is a shortcut for 'deckNumber = decknumber + 2'
        } else {
            deckNumber -= 2 // This is a shortcut for 'deckNumber = decknumber - 2'
        }
        Mixduino.deck[group] = '[Channel' + deckNumber + ']'
        Mixduino.initDeck(Mixduino.deck[group]) // Initialize the new deck. This function is defined below.
    }
}

Mixduino.initDeck = function (group) { // This function is not mapped to a MIDI signal; it is only called by this script in the init and deckToggleButton functions
    // Execute code to set up the controller for manipulating a deck
    // Putting this code in a function allows you to call the same code from the script's init function and the deckToggleButton function without having to copy and paste code
    print("group: " + group)
    print("deckFromGroup: " + script.deckFromGroup(group))
    // Figure out which deck was being controlled before so automatic reactions to changes in Mixxx (see above) can be disabled for that deck
    var disconnectDeck = parseInt(Mixduino.channelRegEx.exec(group)[1])
    if (disconnectDeck <= 2) {
        disconnectDeck += 2
    } else {
        disconnectDeck -= 2
    }
    print("disconected: " + disconnectDeck)
    Mixduino.connectDeckControls('[Channel'+disconnectDeck+']', true) // disconnect old deck's Mixxx controls from LEDs. This function is defined below.
    Mixduino.connectDeckControls(group) // connect new deck's Mixxx controls to LEDs
    engine.softTakeover(group, 'rate', true);
    // Toggle LED that indicates which deck is being controlled
    // midi.sendShortMsg(
    //     0x90,
    //     Mixduino.buttons[group]['deckToggle'],
    //     (disconnectDeck > 2) ? 0x7f : 0x00 // If the condition in parentheses is true, send 0x7f; otherwise, send 0x00
    //                                        // see https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Conditional_Operator
    // )
}

Mixduino.connectDeckControls = function (group, remove) { // This function is not mapped to a MIDI signal; it is only called by this script in the initDeck function below
    // This function either connects or disconnects automatic reactions to changes in Mixxx (see wiki section above), depending on the value of the 'remove' parameter
    // Putting this in its own function allows the same code to be reused for both connecting and disconnecting
    // This is particularly helpful when the list of Mixxx controls connected to LEDs is long
    
    remove = (typeof remove !== 'undefined') ? remove : false // If the 'remove' parameter is not passed to this function, set remove = false
    var controlsToFunctions = { // This hash table maps Mixxx controls to the script functions (not shown in this example) that control LEDs that react to changes in those controls
        'play_indicator': 'Mixduino.playButtonLED',
        'cue_indicator': 'Mixduino.cueButtonLED',
        'loop_enabled': 'Mixduino.loopButtonLED'
        // ... and any other functions that react to changes in Mixxx controls for a deck
    }
    
    for (var control in controlsToFunctions) { // For each property (key: value pair) in controlsToFunctions, control = that property of controlsToFunctions
                                               // see https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...in
        engine.connectControl(group, control, controlsToFunctions[control], remove)
        if (! remove) { // '!' means "not"; it inverts the value of a boolean (true/false)
            engine.trigger(group, control)
        }
    }
}

Mixduino.navigation = new components.Encoder({
    midi: [0xB0, 0x0E],
    group: '[Library]',
    inKey: 'MoveVertical',
    relative: true,
    input: function (channel, control, value, status, group) {
        if (Mixduino.debounce && value === 0x01 ) {
            this.inSetParameter(-1);
            Mixduino.debounce = false;
        } else if (Mixduino.debounce && value === 0x7F) {
            this.inSetParameter(1);
            Mixduino.debounce = false;
        } else {
            Mixduino.debounce = true;
        }
    },
});

Mixduino.touchBar = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] // Change the value of the group variable to the deck we actually want to manipulate based on the state of the deck toggle button
    // --- Choose only one of the following!
    // A: For a control that centers on 0:
    var currentValue = engine.getValue(group, 'jog')
    print('currentValue: ' +currentValue)
    print('value: ' + value/128)
    var newValue;
    // if (value < 64) {
    //     newValue = value;
    // } else {
    //     newValue = value - 128;
    // }
    
    // B: For a control that centers on 0x40 (64):
    // var newValue = currentValue - (32-value) /128;
    var newValue = script.absoluteLin(value, -2, 2, 0, 127)
    print('JOG: ' + newValue)
    // --- End choice
    
    // In either case, register the movement
    engine.setValue(group, 'jog', newValue); // Pitch bend
}

Mixduino.playButton = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] // Change the value of the group variable to the deck we actually want to manipulate based on the state of the deck toggle button
    if (value) {
        // toggle whether the deck is playing
        script.toggleControl(group, 'play')
    }
}

Mixduino.cueButton = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] // Change the value of the group variable to the deck we actually want to manipulate based on the state of the deck toggle button
    if (value) {
        // toggle whether the deck is playing
        script.toggleControl(group, 'cue_cdj')
    }
}

Mixduino.loadButton = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] // Change the value of the group variable to the deck we actually want to manipulate based on the state of the deck toggle button
    if (value) {
        // toggle whether the deck is playing
        script.toggleControl(group, 'LoadSelectedTrack')
        engine.setValue('[Master]', 'maximize_library', 0x00)
    }
}

Mixduino.syncModeButton = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] // Change the value of the group variable to the deck we actually want to manipulate based on the state of the deck toggle button
    if (value) {
        // toggle whether the deck is playing
        script.toggleControl(group, 'sync_mode')
    }
}

Mixduino.loopButton = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] // Change the value of the group variable to the deck we actually want to manipulate based on the state of the deck toggle button
    if (value) {
        // toggle whether the deck is playing
        script.toggleControl(group, 'beatloop_4_toggle')
    }
}

Mixduino.tempoRate = function (channel, control, value, status, group) {
    group = Mixduino.deck[group] 
    if (value) {
        engine.setValue(group, 'rate', script.absoluteLin(value, low, high, min, max))
    }
}

Mixduino.playButtonLED = function ( value, group, control) {
    midi.sendShortMsg(
                        0x90,
                        Mixduino.buttons[group].play,
                        (value === 1) ? Mixduino.colors.blue : Mixduino.colors.off
                    )
}

Mixduino.cueButtonLED = function ( value, group, control) {
    midi.sendShortMsg(
                        0x90,
                        Mixduino.buttons[group].cue,
                        (value === 1) ? Mixduino.colors.blue : Mixduino.colors.off
                    )
}

Mixduino.loopButtonLED = function ( value, group, control) {
    midi.sendShortMsg(
                        0x90,
                        Mixduino.buttons[group].loop,
                        (value === 1) ? Mixduino.colors.blue : Mixduino.colors.off
                    )
}





