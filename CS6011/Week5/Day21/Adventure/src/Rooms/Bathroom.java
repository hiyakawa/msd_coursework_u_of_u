package Rooms;

import Items.Item;

public class Bathroom extends Room {

    public Bathroom() {
        super("Bathroom", "A bathroom with faucets and empty bottles.");
        Item faucet = new Item( "Faucet", "Turn it on and get water.");
        items_.add(faucet);
    }
}
