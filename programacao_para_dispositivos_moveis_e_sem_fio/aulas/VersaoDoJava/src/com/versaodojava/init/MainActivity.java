package com.versaodojava.init;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.versaodojava.ObterString;
import com.versaodojava.R;
import com.versaodojava.VersaoDoJava;

public class MainActivity extends Activity {
	
	private static final int reqCode = 1;
	private static final int reqObter = 2;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		Intent intent = new Intent(this, VersaoDoJava.class);
		startActivityForResult(intent, reqCode);
	}
	
	public void obterString(View componente) {
		Intent intent = new Intent(this, ObterString.class);
		startActivityForResult(intent, reqObter);
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO Auto-generated method stub
		if (requestCode == reqCode) {
			if (resultCode == RESULT_OK){
				Toast.makeText(this, data.getStringExtra("VERSAO"), Toast.LENGTH_LONG).show();
			}
		}
		else if (requestCode == reqObter) {
			if (resultCode == RESULT_OK){
				((TextView)findViewById(R.id.textView1)).setText(data.getStringExtra("OLA"));
			}
		}
	}
}
