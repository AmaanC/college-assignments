// This doesn't seem to work for some reason. No idea why, since I have no errors.
import java.awt.*;
import java.applet.*;

public class AudioApplet extends Applet {
    AudioClip clip;
    public void init() {
        clip = getAudioClip(getCodeBase(), "song.mp3");
    }

    public void start() {
        clip.play();
    }
}
/*
<applet code="AudioApplet.class" width="100" height="100"></applet>
*/