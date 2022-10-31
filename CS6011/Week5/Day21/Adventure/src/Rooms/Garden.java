package Rooms;

import Items.Item;

public class Garden extends Room {
    protected boolean watered_ = false;
    public Garden() {
        super("Garden", "A garden with variable plants.");
        Item roses = new Item( "Roses", "The roses are wilted.");
        items_.add(roses);
    }

    @Override
    public void playerEntered() {
        if (! watered_) {
            System.out.println( "The roses are wilted: they are out of water." );
        }
    }
}
