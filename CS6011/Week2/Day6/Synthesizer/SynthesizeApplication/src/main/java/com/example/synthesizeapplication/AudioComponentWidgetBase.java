package com.example.synthesizeapplication;

import javafx.geometry.Bounds;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.control.Button;
import javafx.scene.shape.Line;

import static com.example.synthesizeapplication.SynthesizeApplication.SPEAKER_RADIUS;

public class AudioComponentWidgetBase extends Pane {
    private AudioComponent audioComponent_;
    private AnchorPane parent_;
    private HBox baseLayout;
    private String name_;
    private Line line_;
    private Label nameLable_;
    private double mouseStartDragX_, mouseStartDragY_;
    private double widgetStartDragX_, widgetStartDragY_;

    AudioComponentWidgetBase(AudioComponent ac, AnchorPane parent, String name) {
        audioComponent_ = ac;
        parent_ = parent;
        name_ = name;

        baseLayout = new HBox();
        baseLayout.setStyle("-fx-border-color: darkgray;" +
                            "-fx-border-image-width: 4;" +
                            "-fx-background-color: white");
        this.getChildren().add(baseLayout);

        // center
        VBox center = new VBox();
        center.setAlignment(Pos.CENTER);

        nameLable_ = new Label();
        nameLable_.setMouseTransparent(true);
        nameLable_.setText("    Sine Wave\n    (440 Hz)");

        Slider slider = new Slider(220, 880, 440);
        slider.setOrientation(Orientation.VERTICAL);
        slider.setOnMouseDragged(e-> handleSlider(e, slider));

        center.getChildren().addAll(nameLable_, slider);

        center.setOnMousePressed(e -> startDrag(e));
        center.setOnMouseDragged(e -> handleDrag(e));

        // right
        VBox rightSide = new VBox();
        rightSide.setAlignment(Pos.CENTER);
        rightSide.setPadding(new Insets(5));
        rightSide.setSpacing(5);

        Button closeBtn = new Button("X");
        closeBtn.setOnAction(e -> closeWidget());

        Circle output = new Circle(10);
        output.setFill(Color.PINK);

        output.setOnMousePressed(e -> startConnection(e, output));
        output.setOnMouseDragged(e -> moveConnection(e));
        output.setOnMouseReleased(e -> endConnection(e));

        rightSide.getChildren().addAll(closeBtn, output);
        baseLayout.getChildren().addAll(center, rightSide);
        parent_.getChildren().add(this);
    }

    private void startDrag(MouseEvent e) {
        mouseStartDragX_ = e.getSceneX();
        mouseStartDragY_ = e.getSceneY();

        widgetStartDragX_ = this.getLayoutX();
        widgetStartDragY_ = this.getLayoutY();
    }

    private void handleDrag(MouseEvent e) {
        double mouseDelX = e.getSceneX() - mouseStartDragX_;
        double mouseDelY = e.getSceneY() - mouseStartDragY_;
        this.relocate(widgetStartDragX_ + mouseDelX,
                  widgetStartDragY_ + mouseDelY);
    }

    private void closeWidget() {
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

    private void handleSlider(MouseEvent e, Slider slider) {
        double frequency = slider.getValue();
        nameLable_.setText("    Sine Wave\n    (" + (int) frequency + " Hz)");
        ((SineWave) audioComponent_).setFrequency(frequency);
    }

    private void startConnection(MouseEvent e, Circle output) {
        if (line_ != null) {
            parent_.getChildren().remove(line_);
        }

        Bounds parentBounds = parent_.getBoundsInParent();
        Bounds bounds = output.localToScene(output.getBoundsInLocal());

        line_ = new Line();
        line_.setStyle("-fx-stroke: gray;");
        line_.setStrokeWidth(3);
        line_.setStartX(bounds.getCenterX() - parentBounds.getMinX());
        line_.setStartY(bounds.getCenterY() - parentBounds.getMinY());
        line_.setEndX(e.getSceneX());
        line_.setEndY(e.getSceneY());
        parent_.getChildren().add(line_);
    }

    private void moveConnection(MouseEvent e) {
        Bounds parentBounds = parent_.getBoundsInParent();
        line_.setEndX(e.getSceneX() - parentBounds.getMinX());
        line_.setEndY(e.getSceneY() - parentBounds.getMinY());
    }

    private void endConnection(MouseEvent e) {
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
