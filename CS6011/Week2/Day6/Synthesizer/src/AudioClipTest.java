import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class AudioClipTest {
    @Test
    public void testGetSample() {
        AudioClip audioClip = new AudioClip();
        int index = 5;

        short maxValue = Short.MAX_VALUE;
        short minValue = Short.MIN_VALUE;

        audioClip.setSample(index, maxValue);
        short testMaxValue = (short) audioClip.getSample(index);
        audioClip.setSample(index, minValue);
        short testMinValue = (short) audioClip.getSample(index);

        Assertions.assertEquals(maxValue, testMaxValue);
        Assertions.assertEquals(minValue, testMinValue);
    }
}