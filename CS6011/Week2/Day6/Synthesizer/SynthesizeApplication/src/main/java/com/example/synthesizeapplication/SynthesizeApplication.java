package com.example.synthesizeapplication;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import java.io.IOException;
import java.util.ArrayList;

public class SynthesizeApplication extends Application {
    private AnchorPane mainCanvas_;
    private double layoutX_ = 20;
    private double layoutY_ = 20;
    public static Circle speaker_;
    public static int SPEAKER_RADIUS = 20;
    public static ArrayList<AudioComponentWidgetBase> widgets_ = new ArrayList<>();
    public static ArrayList<AudioComponentWidgetBase> widgetsConnectedToSpeaker_ = new ArrayList<>();

    @Override
    public void start(Stage stage) throws IOException {
        BorderPane root = new BorderPane();
        Scene scene = new Scene(root, 900, 600);

        // center panel
        mainCanvas_ = new AnchorPane();
        mainCanvas_.setStyle("-fx-background-color: lightgray");

        // speaker
        speaker_ = new Circle(450, 450, SPEAKER_RADIUS, Color.GRAY);
        mainCanvas_.getChildren().add(speaker_);

        // top panel
        HBox menu = new HBox();
        menu.setStyle("-fx-background-color: darkgray");
        Button cBtn = new Button("C4");
        Button dBtn = new Button("D4");
        Button eBtn = new Button("E4");
        Button fBtn = new Button("F4");
        Button gBtn = new Button("G4");
        Button aBtn = new Button("A4");
        Button bBtn = new Button("B4");

        // reference: https://en.wikipedia.org/wiki/Piano_key_frequencies
        cBtn.setOnAction(e -> playKey(261.6256));
        dBtn.setOnAction(e -> playKey(293.6648));
        eBtn.setOnAction(e -> playKey(329.6276));
        fBtn.setOnAction(e -> playKey(349.2282));
        gBtn.setOnAction(e -> playKey(391.9954));
        aBtn.setOnAction(e -> playKey(440.0000));
        bBtn.setOnAction(e -> playKey(493.8833));

        menu.getChildren().addAll(cBtn, dBtn, eBtn, fBtn, gBtn, aBtn, bBtn);

        // left panel
        VBox leftPanel = new VBox();
        leftPanel.setStyle("-fx-background-color: gray");

        // right panel
        VBox rightPanel = new VBox();
        rightPanel.setStyle("-fx-background-color: gray");
        rightPanel.setPadding(new Insets(4));

        Button sineWaveBtn = new Button("Sine Wave");
        rightPanel.getChildren().add(sineWaveBtn);
        sineWaveBtn.setOnAction(e -> createComponent("Sine Wave"));

        // bottom panel
        HBox bottomPanel = new HBox();
        Button playBtn = new Button("Play");
        playBtn.setAlignment(Pos.CENTER);
        playBtn.setOnAction(e -> play());

        bottomPanel.getChildren().add(playBtn);

        menu.setAlignment(Pos.CENTER);
        menu.setSpacing(50);
        menu.setPadding(new Insets(10));

        root.setCenter(mainCanvas_);
        root.setTop(menu);
        root.setLeft(leftPanel);
        root.setRight(rightPanel);
        root.setBottom(bottomPanel);

        stage.setTitle("Synthesizer");
        stage.setScene(scene);
        stage.show();
    }

    private void playKey(double frequency) {
        try {
            Clip c = AudioSystem.getClip();
            AudioListener listener = new AudioListener(c);
            AudioFormat format16 = new AudioFormat(44100, 16, 1, true, false);

            AudioComponent key = new SineWave(frequency);
            AudioClip clip = key.getClip();

            c.open(format16, clip.getData(), 0, clip.getData().length);
            c.start();
            c.addLineListener(listener);
        }
        catch (LineUnavailableException e) {
            throw new RuntimeException(e);
        }
    }

    private void play() {
        if (widgets_.size() == 0) {
            return;
        }
        try {
            Clip c = AudioSystem.getClip();
            AudioListener listener = new AudioListener(c);
            Mixer mixer = new Mixer();

            for (AudioComponentWidgetBase w : widgetsConnectedToSpeaker_) {
                AudioComponent ac = w.getAudioComponent();
                mixer.connectInput(ac);
            }

            byte [] data = mixer.getClip().getData();
            AudioFormat format = new AudioFormat(44100, 16, 1, true, false);

            c.open(format, data, 0, data.length);
            c.start();
            c.addLineListener(listener);
        }
        catch (LineUnavailableException e) {
            throw new RuntimeException(e);
        }
    }

    private void createComponent(String sineWave) {
        AudioComponent sinewave = new SineWave(440);
        AudioComponentWidgetBase acw = new AudioComponentWidgetBase(sinewave, mainCanvas_, "Sine Wave");
        widgets_.add(acw);
        acw.setLayoutX(layoutX_);
        acw.setLayoutY(layoutY_);

        // avoid the widgets from being overlaid
        if (layoutX_ < 600 && layoutY_ < 400) {
            layoutX_ += 120;
        }
        else if (layoutY_ < 200) {
            layoutX_ = 20;
            layoutY_ += 200;
        }
        else {
            layoutX_ -= 600;
            layoutY_ -= 180;
        }
    }

    public static void main(String[] args) {
        launch();
    }
}