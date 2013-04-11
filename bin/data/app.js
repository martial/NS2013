println("-- app.js -- ");
include("Scripts/libraries/fieldkit/src/Header.js");
include("Scripts/libraries/fieldkit/src/Class.js");
include("Scripts/libraries/fieldkit/src/math/Math.js");
include("Scripts/libraries/fieldkit/src/math/Vec2.js");
include("Scripts/libraries/fieldkit/src/math/Vec3.js");
include("Scripts/libraries/tween.min.js")
include("Scripts/libraries/SimplexNoise.js")
include("Scripts/libraries/EasedPct.js")

// ----------------------------
// Global variables and functions

var numSharpy           = 32;
var leftSharpies        = new Array();
var rightSharpies       = new Array();
var horizontalSharpies  = new Array();

var animations          = new Array();
var previewAnimIndex    = 0;

var speedPct            = 1.0;
var timeMillis          = 0.0;

var yoyoPct             = 0.0;

var tween = new TWEEN.Tween(yoyoPct)
    .to(1.0,.0)
    .easing(TWEEN.Easing.Quintic.Out)
    .start();

function setVariables() {

    for (var i = 0; i < 2; i++) {

        for (var j = 0; j < 16; j++) {

            var index = i * 16 + j;

            if (i == 0)
                leftSharpies.push(index);
            else
                rightSharpies.push(index);
        }

    }

    for (var j = 0; j < 16; j++) {

        for (var i = 0; i < 2; i++) {

            var index = i * 16 + j;
            horizontalSharpies.push(index);

        }

    }

}

function normalize(val, max) {

    return val / max;

}

function radians(deg) {
    return deg * Math.PI / 180;
}

function setPreviewAnim(index) {
    previewAnimation = animations[index];

}

function nextPreviewAnim() {

    previewAnimIndex++;
    if (previewAnimIndex == animations.length)
        previewAnimIndex = 0;
    setPreviewAnim(previewAnimIndex);

}

// Effects -------------------------------------

function strobGobo(object) {
    object.gobo = Math.random();

}

function strob(object) {
    object.gobo = Math.random();
    object.brt = Math.random();

}

// -------------------------------------

function setup() {

    mainAnimation.setup(0);
    if(previewAnimation)previewAnimation.setup(1);
}

function update(speed, timeMs) {

    TWEEN.update();
    speedPct    = speed;
    timeMillis  = timeMs;

   // println(speed);


    mainAnimation.update(0);
    if(previewAnimation)previewAnimation.update(1);
}

var Animation = fk.Class.extend({

    init: function (name) {

        // set name and default for main ( reloading )
        this.name = name;
        animations.push(this);
        mainAnimation = this;

    },

    setup: function (s) {

        // set everything to default if not defined
        for (var i = 0; i < numSharpy; i++) {

            setOrientation  (s, i, 0 , 0, 0);
            setGobo         (s, i, 1.0);
            setBrightness   (s, i, 1.0);

        }

    },

    update: function () {
    }
});

// defaults
var mainAnimation = new Animation("");
var previewAnimation = null;

setVariables();