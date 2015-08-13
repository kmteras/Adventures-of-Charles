﻿using UnityEngine;
using System.Collections;

public class GameController : MonoBehaviour {

    private int width, height;

	void Start () {
        ChangeCameraSize();
        width = Screen.width;
        height = Screen.height;
	}
	
	void Update () {
        if(width != Screen.width || height != Screen.height) {
            ChangeCameraSize();
            width = Screen.width;
            height = Screen.height; 
        }
	}

    void ChangeCameraSize() {
        Camera.main.orthographicSize = (Screen.height / 100f / 2.0f) / 2;
    }
}
