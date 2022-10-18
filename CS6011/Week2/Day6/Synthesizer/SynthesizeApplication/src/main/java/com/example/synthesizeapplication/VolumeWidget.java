package com.example.synthesizeapplication;

import javafx.geometry.Bounds;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;

import static com.example.synthesizeapplication.SineWaveWidgets.CIRCLE_RADIUS;

public class VolumeWidget extends AudioComponentWidgetBase {
    private AudioComponent audioComponent_;
    private AnchorPane parent_;
    private HBox baseLayout;
    private String name_;
    protected static Line line_;
    private Label nameLable_;
    private Circle output_;
    private double mouseStartDragX_, mouseStartDragY_;
    private double widgetStartDragX_, widgetStartDragY_;
    public static ArrayList<AudioComponentWidgetBase> widgetsConnectedToVolume_ = new ArrayList<>();

    VolumeWidget(AudioComponent ac, AnchorPane parent, String name) {
        super(ac, parent, name);
        audioComponent_ = ac;
        parent_ = parent;
        name_ = name;

        baseLayout = new HBox();
        baseLayout.setStyle("-fx-border-color: darkgray;" +
                "-fx-border-image-width: 4;" +
                "-fx-background-color: #ffffff");
        this.getChildren().add(baseLayout);

        // center
        VBox center = new VBox();
        center.setAlignment(Pos.CENTER);

        nameLable_ = new Label();
        nameLable_.setMouseTransparent(true);
        nameLable_.setText("    Volume Scale\n          × 1.00");

        Slider slider = new Slider(0, 5, 1);
        slider.setOrientation(Orientation.VERTICAL);
        slider.setOnMouseDragged(e-> handleSlider(slider));

        center.getChildren().addAll(nameLable_, slider);

        center.setOnMousePressed(e -> startDrag(e));
        center.setOnMouseDragged(e -> handleDrag(e));

        // right
        VBox rightSide = new VBox();
        rightSide.setAlignment(Pos.CENTER);
        rightSide.setPadding(new Insets(5));
        rightSide.setSpacing(5);

        Button closeBtn = new Button("×");
        closeBtn.setOnAction(e -> closeWidget());

        output_ = new Circle(10);
        output_.setFill(Color.LIGHTGRAY);

        output_.setOnMousePressed(e -> startConnection(e, output_));
        output_.setOnMouseDragged(e -> moveConnection(e));
        output_.setOnMouseReleased(e -> endConnection(e));

        rightSide.getChildren().addAll(closeBtn, output_);
        baseLayout.getChildren().addAll(center, rightSide);
        parent_.getChildren().add(this);
    }

    void startDrag(MouseEvent e) {
        mouseStartDragX_ = e.getSceneX();
        mouseStartDragY_ = e.getSceneY();

        widgetStartDragX_ = this.getLayoutX();
        widgetStartDragY_ = this.getLayoutY();
    }

    void handleDrag(MouseEvent e) {
        double mouseDelX = e.getSceneX() - mouseStartDragX_;
        double mouseDelY = e.getSceneY() - mouseStartDragY_;
        this.relocate(widgetStartDragX_ + mouseDelX,
                widgetStartDragY_ + mouseDelY);

        Bounds parentBounds = parent_.getBoundsInParent();
        Bounds bounds = output_.localToScene(output_.getBoundsInLocal());

        if (line_ != null) {
            line_.setStartX(bounds.getCenterX() - parentBounds.getMinX());
            line_.setStartY(bounds.getCenterY() - parentBounds.getMinY());
        }
    }

    void closeWidget() {
        parent_.getChildren().remove(this);
        SynthesizeApplication.widgets_.remove(this);
        SynthesizeApplication.widgetsConnectedToSpeaker_.remove(this);

        if (line_ != null) {
            parent_.getChildren().remove(line_);
        }
    }

    public AudioComponent getAudioComponent() {
        return audioComponent_;
    }

    void handleSlider(Slider slider) {
        double scale = slider.getValue();
        nameLable_.setText("    Volume Scale\n          × " + round(scale, 2));
        ((Filter) audioComponent_).setScale_(scale);
    }

    void startConnection(MouseEvent e, Circle output) {
        if (line_ != null) {
            parent_.getChildren().remove(line_);
        }

        Bounds parentBounds = parent_.getBoundsInParent();
        Bounds bounds = output.localToScene(output.getBoundsInLocal());

        line_ = new Line();
        line_.setStyle("-fx-stroke: #d3d0c9;");
        line_.setStrokeWidth(2);
        line_.setStartX(bounds.getCenterX() - parentBounds.getMinX());
        line_.setStartY(bounds.getCenterY() - parentBounds.getMinY());
        line_.setEndX(e.getSceneX());
        line_.setEndY(e.getSceneY());
        parent_.getChildren().add(line_);
    }

    void moveConnection(MouseEvent e) {
        Bounds parentBounds = parent_.getBoundsInParent();
        line_.setEndX(e.getSceneX() - parentBounds.getMinX());
        line_.setEndY(e.getSceneY() - parentBounds.getMinY());
    }

    void endConnection(MouseEvent e) {
        Circle volumeCircle = SineWaveWidgets.volumeCircle_;
        Bounds volumeCircleBounds = volumeCircle.localToScreen(volumeCircle.getBoundsInLocal());
        double distance = Math.sqrt(Math.pow(volumeCircleBounds.getCenterX() - e.getScreenX(), 2.0) +
                Math.pow(volumeCircleBounds.getCenterY() - e.getScreenY(), 2.0));

        if (distance < CIRCLE_RADIUS) {
            VolumeWidget.widgetsConnectedToVolume_.add(this);
        }
        else {
            parent_.getChildren().remove(line_);
            line_ = null;
            VolumeWidget.widgetsConnectedToVolume_.remove(this);
        }
    }

    public static double round(double value, int places) {
        if (places < 0) throw new IllegalArgumentException();

        BigDecimal bd = BigDecimal.valueOf(value);
        bd = bd.setScale(places, RoundingMode.HALF_UP);
        return bd.doubleValue();
    }
}
