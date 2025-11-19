package com.csu.boom.Util.Util;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.IOException;

public class Manager {
    private static Manager manager = new Manager();
    public static final int WIDTH=960,HEIGHT=540;
    private Manager() {};
    public static Manager getInstance() {
        return manager;
    }
    public  void init(Stage stage ){
        try{
            Pane pane= FXMLLoader.load(getClass().getResource("/fxml/index.fxml"));
            stage.setScene(new Scene(pane));
            stage.setResizable(false);
            stage.setHeight(HEIGHT);
            stage.setWidth(WIDTH);
            stage.show();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
