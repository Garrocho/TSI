package com.versaodojava;

import android.app.Activity;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;

public class VersaoDoJava extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_versao_do_java);
		
		String versao = Build.VERSION.RELEASE;
		Intent intent = new Intent();
		
		intent.putExtra("VERSAO", versao);
		setResult(RESULT_OK, intent);
		finish();
	}
}