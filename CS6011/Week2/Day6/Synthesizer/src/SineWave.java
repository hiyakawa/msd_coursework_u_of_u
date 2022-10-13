import static java.lang.Math.PI;
import static java.lang.Math.sin;

public class SineWave implements AudioComponent {
    private final int frequency_;

    public SineWave(int frequency) {
        frequency_ = frequency;
    }

    @Override
    public AudioClip getClip() {
        AudioClip audioClip = new AudioClip();
        short maxValue = Short.MAX_VALUE;

        for (int i = 0; i < AudioClip.TOTAL_SAMPLES; i++) {
            audioClip.setSample(i, (short) (maxValue * sin(2 * PI * frequency_ * i / audioClip.getSampleRate())));
        }
        return audioClip;
    }

    @Override
    public boolean hasInput() {
        return false;
    }

    @Override
    public void connectInput(AudioComponent input) {

    }
}
