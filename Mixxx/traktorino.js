var Traktorino = {};
 
Traktorino.init = function () {
    Traktorino.leftDeck = new Traktorino.Deck([1,3],1);
    Traktorino.rightDeck = new Traktorino.Deck([2,4],2);
}

Traktorino.shutdown = function() {
    // left deck leds
    midi.sendShortMsg(0x80, 0x28, 0x00); // left sync
    midi.sendShortMsg(0x80, 0x27, 0x00); // left cue
    midi.sendShortMsg(0x80, 0x26, 0x00); // left play
    midi.sendShortMsg(0x80, 0x25, 0x00); // left phones
    midi.sendShortMsg(0x80, 0x24, 0x00); // filter on

    // right deck leds
    midi.sendShortMsg(0x80, 0x2C, 0x00); // sync
    midi.sendShortMsg(0x80, 0x2D, 0x00); // cue
    midi.sendShortMsg(0x80, 0x2E, 0x00); // play
    midi.sendShortMsg(0x80, 0x2F, 0x00); // phones
    midi.sendShortMsg(0x80, 0x30, 0x00); // filter on

    // VU meters
    midi.sendShortMsg(0xB1, 0x0C, 0x01); // VU meter left
    midi.sendShortMsg(0xB1, 0x0C, 0x00); // VU meter left
    midi.sendShortMsg(0xB1, 0x0D, 0x01); // VU meter right
    midi.sendShortMsg(0xB1, 0x0D, 0x00); // VU meter right
}

Traktorino.Deck = function (deckNumbers, midiChannel) {
    components.Deck.call(this, midiChannel);
    if( midiChannel == 1){
        this.playButton = new components.PlayButton([0x90 + midiChannel, 0x26]);
        this.cueButton = new components.CueButton([0x90 + midiChannel, 0x027]);
        this.syncButton = new components.SyncButton([0x90 + midiChannel, 0x028]);
        this.pflButton = new components.Button({
            midi: [0x90 + midiChannel, 0x25],
            group: '[Channel1]',
            key: 'pfl',
            type: components.Button.prototype.types.toggle,
        });

        this.volume = new components.Pot({
            midi: [0xBA, 0x02],
            group: '[Channel1]',
            inKey: 'volume',
            relative: true,
        });

        this.pregain = new components.Pot({
            midi: [0xBA, 0x07],
            group: '[Channel1]',
            inKey: 'pregain',
            relative: true,
        });

        this.highFilter = new components.Pot({
            midi: [0xBA, 0x06],
            group: '[EqualizerRack1_[Channel1]_Effect1]',
            inKey: 'parameter3',
            relative: true,
        });

        this.midFilter = new components.Pot({
            midi: [0xBA, 0x05],
            group: '[EqualizerRack1_[Channel1]_Effect1]',
            inKey: 'parameter2',
            relative: true,
        });

        this.lowFilter = new components.Pot({
            midi: [0xBA, 0x04],
            group: '[EqualizerRack1_[Channel1]_Effect1]',
            inKey: 'parameter1',
            relative: true,
        });

        this.filterPot = new components.Pot({
            midi: [0xBA, 0x03],
            group: '[QuickEffectRack1_[Channel1]]',
            inKey: 'super1',
            relative: true,
        });

        this.filterButton = new components.Button({
            midi: [0x90 +midiChannel, 0x09],
            group: '[QuickEffectRack1_[Channel1]]',
            inKey: 'enabled',
            type: components.Button.prototype.types.toggle,
        });
    }

    if( midiChannel == 2){
        this.playButton = new components.PlayButton([0x90 + midiChannel, 0x2E]);
        this.cueButton = new components.CueButton([0x90 + midiChannel, 0x02D]);
        this.syncButton = new components.SyncButton([0x90 + midiChannel, 0x02C]);
        this.pflButton = new components.Button({
            midi: [0x90 + midiChannel, 0x2F],
            group: '[Channel2]',
            key: 'pfl',
            type: components.Button.prototype.types.toggle,
        });

        this.volume = new components.Pot({
            midi: [0xBA, 0x08],
            group: '[Channel2]',
            inKey: 'volume',
            relative: true,
        });

        this.pregain = new components.Pot({
            midi: [0xBA, 0x0D],
            group: '[Channel2]',
            inKey: 'pregain',
            relative: true,
        });

        this.highFilter = new components.Pot({
            midi: [0xBA, 0x0C],
            group: '[EqualizerRack1_[Channel2]_Effect1]',
            inKey: 'parameter3',
            relative: true,
        });

        this.midFilter = new components.Pot({
            midi: [0xBA, 0x0B],
            group: '[EqualizerRack1_[Channel2]_Effect1]',
            inKey: 'parameter2',
            relative: true,
        });

        this.lowFilter = new components.Pot({
            midi: [0xBA, 0x0A],
            group: '[EqualizerRack1_[Channel2]_Effect1]',
            inKey: 'parameter1',
            relative: true,
        });

        this.filterPot = new components.Pot({
            midi: [0xBA, 0x09],
            group: '[QuickEffectRack1_[Channel2]]',
            inKey: 'super1',
            relative: true,
        });

        this.filterButton = new components.Button({
            midi: [0x90 + midiChannel, 0x30],
            group: '[QuickEffectRack1_[Channel2]]',
            inKey: 'enabled',
            type: components.Button.prototype.types.toggle,
        });
    }

    this.reconnectComponents(function (c) {
        if (c.group === undefined) {
            c.group = this.currentDeck;
        }
    });
};



Traktorino.crossFader = new components.Pot({
    midi: [0xBA, 0x01],
    group: '[Master]',
    inKey: 'crossfader',
    relative: true,
});

Traktorino.masterGain = new components.Pot({
    midi: [0xBA, 0x0E],
    group: '[Master]',
    inKey: 'gain',
    relative: true,
});


Traktorino.libEncoder = new components.Encoder({
    midi: [0xB0, 0x0E],
    group: '[Library]',
    inKey: 'MoveVertical',
    relative: true,
    input: function (channel, control, value, status, group) {
        if (value === 0x01) {
            this.inSetParameter(-1);
        } else if (value === 0x7F) {
            this.inSetParameter(1);
        }
    },
});

Traktorino.loadAButton = new components.Button({
    midi: [0x90, 0x29],
    group: '[Channel1]',
    inKey: 'LoadSelectedTrack',
});


Traktorino.loadBButton = new components.Button({
    midi: [0x90, 0x2B],
    group: '[Channel2]',
    inKey: 'LoadSelectedTrack',
});

Traktorino.VuMeterL = engine.makeConnection("[Master]","VuMeterL",function (value) {

    if(value<=0.05){
        midi.sendShortMsg(0xB1, 0x0C, 0x01);
        midi.sendShortMsg(0xB1, 0x0C, 0x00);
    }
    else if(value<=0.15){
        midi.sendShortMsg(0xB1, 0x0C, 0x00);
        midi.sendShortMsg(0xB1, 0x0C, 0x01);
    }
    else if(value<=0.3){
        midi.sendShortMsg(0xB1, 0x0C, 0x01);
        midi.sendShortMsg(0xB1, 0x0C, 0x02);
    }
    else if(value<=0.45){
        midi.sendShortMsg(0xB1, 0x0C, 0x02);
        midi.sendShortMsg(0xB1, 0x0C, 0x03);
    }
    else if(value<=0.6){
        midi.sendShortMsg(0xB1, 0x0C, 0x03);
        midi.sendShortMsg(0xB1, 0x0C, 0x04);
    }
    else if(value<=0.7){
        midi.sendShortMsg(0xB1, 0x0C, 0x04);
        midi.sendShortMsg(0xB1, 0x0C, 0x05);
    }
    else if(value<=0.8){
        midi.sendShortMsg(0xB1, 0x0C, 0x05);
        midi.sendShortMsg(0xB1, 0x0C, 0x06);
    }
    else if(value<=0.9){
        midi.sendShortMsg(0xB1, 0x0C, 0x06);
        midi.sendShortMsg(0xB1, 0x0C, 0x07);
    }
});

Traktorino.VuMeterR = engine.makeConnection("[Master]","VuMeterR",function (value) {
    // sending double state change because of smoothness
    if(value<=0.05){
        midi.sendShortMsg(0xB1, 0x0D, 0x01);
        midi.sendShortMsg(0xB1, 0x0D, 0x00);
    }
    else if(value<=0.15){
        midi.sendShortMsg(0xB1, 0x0D, 0x00);
        midi.sendShortMsg(0xB1, 0x0D, 0x01);
    }
    else if(value<=0.3){
        midi.sendShortMsg(0xB1, 0x0D, 0x01);
        midi.sendShortMsg(0xB1, 0x0D, 0x02);
    }
    else if(value<=0.45){
        midi.sendShortMsg(0xB1, 0x0D, 0x02);
        midi.sendShortMsg(0xB1, 0x0D, 0x03);
    }
    else if(value<=0.6){
        midi.sendShortMsg(0xB1, 0x0D, 0x03);
        midi.sendShortMsg(0xB1, 0x0D, 0x04);
    }
    else if(value<=0.7){
        midi.sendShortMsg(0xB1, 0x0D, 0x04);
        midi.sendShortMsg(0xB1, 0x0D, 0x05);
    }
    else if(value<=0.8){
        midi.sendShortMsg(0xB1, 0x0D, 0x05);
        midi.sendShortMsg(0xB1, 0x0D, 0x06);
    }
    else if(value<=0.9){
        midi.sendShortMsg(0xB1, 0x0D, 0x06);
        midi.sendShortMsg(0xB1, 0x0D, 0x07);
    }
});

Traktorino.Deck.prototype = new components.Deck();