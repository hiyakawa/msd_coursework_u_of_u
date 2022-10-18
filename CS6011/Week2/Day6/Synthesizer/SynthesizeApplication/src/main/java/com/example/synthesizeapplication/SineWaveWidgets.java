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

import static com.example.synthesizeapplication.SynthesizeApplication.SPEAKER_RADIUS;

public class SineWaveWidgets extends AudioComponentWidgetBase {
    private AudioComponent audioComponent_;
    private AnchorPane parent_;
    private HBox baseLayout_;
    private String name_;
    private Label nameLable_;
    private Line line_;
    private Circle outputCircle_;
    public static Circle volumeCircle_;
    public static int CIRCLE_RADIUS = 10;
    private double mouseStartDragX_, mouseStartDragY_;
    private double widgetStartDragX_, widgetStartDragY_;

    SineWaveWidgets(AudioComponent ac, AnchorPane parent, String name) {
        super(ac, parent, name);
        audioComponent_ = ac;
        parent_ = parent;
        name_ = name;

        baseLayout_ = new HBox();
        baseLayout_.setStyle("-fx-border-color: darkgray;" +
                "-fx-border-image-width: 4;" +
                "-fx-background-color: #ffffff");
        this.getChildren().add(baseLayout_);

        // center
        VBox center = new VBox();
        center.setAlignment(Pos.CENTER);

        nameLable_ = new Label();
        nameLable_.setMouseTransparent(true);
        nameLable_.setText("    Sine Wave\n        440 Hz");

        Slider slider = new Slider(220, 880, 440);
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

        volumeCircle_ = new Circle(CIRCLE_RADIUS);
        volumeCircle_.setFill(Color.LIGHTGRAY);

        outputCircle_ = new Circle(CIRCLE_RADIUS);
        outputCircle_.setFill(Color.GRAY);

        outputCircle_.setOnMousePressed(e -> startConnection(e, outputCircle_));
        outputCircle_.setOnMouseDragged(e -> moveConnection(e));
        outputCircle_.setOnMouseReleased(e -> endConnection(e));

        rightSide.getChildren().addAll(closeBtn, volumeCircle_, outputCircle_);
        baseLayout_.getChildren().addAll(center, rightSide);
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
        Bounds outputBounds = outputCircle_.localToScene(outputCircle_.getBoundsInLocal());
        Bounds volumeBounds = volumeCircle_.localToScene(outputCircle_.getBoundsInLocal());

        if (line_ != null) {
            line_.setStartX(outputBounds.getCenterX() - parentBounds.getMinX());
            line_.setStartY(outputBounds.getCenterY() - parentBounds.getMinY());
        }

        if (VolumeWidget.line_ != null) {
            VolumeWidget.line_.setEndX(volumeBounds.getCenterX() - parentBounds.getMinX());
            VolumeWidget.line_.setEndY(volumeBounds.getCenterY() - parentBounds.getMinY());
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
        double frequency = slider.getValue();
        nameLable_.setText("    Sine Wave\n        " + (int) frequency + " Hz");
        ((SineWave) audioComponent_).setFrequency(frequency);
    }

    void startConnection(MouseEvent e, Circle output) {
        if (line_ != null) {
            parent_.getChildren().remove(line_);
        }

        Bounds parentBounds = parent_.getBoundsInParent();
        Bounds bounds = output.localToScene(output.getBoundsInLocal());

        line_ = new Line();
        line_.setStyle("-fx-stroke: #808080");
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
        Circle speaker = SynthesizeApplication.speaker_;
        Bounds speakerBounds = speaker.localToScreen(speaker.getBoundsInLocal());
        double distance = Math.sqrt(Math.pow(speakerBounds.getCenterX() - e.getScreenX(), 2.0) +
                Math.pow(speakerBounds.getCenterY() - e.getScreenY(), 2.0));

        if (distance < SPEAKER_RADIUS) {
            SynthesizeApplication.widgetsConnectedToSpeaker_.add(this);
        }
        else {
            parent_.getChildren().remove(line_);
            line_ = null;
            SynthesizeApplication.widgetsConnectedToSpeaker_.remove(this);
        }
    }
}
