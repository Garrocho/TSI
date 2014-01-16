package com.versaodojava;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

public class ObterString extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_obter_string);
		
		String ola = "Ola Mundo";
		Intent intent = new Intent();
		
		intent.putExtra("OLA", ola);
		setResult(RESULT_OK, intent);
		finish();
	}
}
