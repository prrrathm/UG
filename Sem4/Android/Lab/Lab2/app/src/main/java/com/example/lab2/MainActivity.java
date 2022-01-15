package com.example.lab2;
import android.os.Bundle;
import com.google.android.material.snackbar.Snackbar;
import androidx.appcompat.app.AppCompatActivity;
import android.view.View;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;
import com.example.lab2.databinding.ActivityMainBinding;
import android.view.Menu;
import android.view.MenuItem;


import android.app.Activity;
import android.util.Log;

public class MainActivity extends Activity {


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Log.d("lifecycle","onCreate invoked");
	}
	@Override
	protected void onStart() {
		super.onStart();
		Log.d("lifecycle","onStart invoked");
	}
	@Override
	protected void onResume() {
		super.onResume();
		Log.d("lifecycle","onResume invoked");
	}
	@Override
	protected void onPause() {
		super.onPause();
		Log.d("lifecycle","onPause invoked");
	}
	@Override
	protected void onStop() {
		super.onStop();
		Log.d("lifecycle","onStop invoked");
	}
	@Override
	protected void onRestart() {
		super.onRestart();
		Log.d("lifecycle","onRestart invoked");
	}
	@Override
	protected void onDestroy() {
		super.onDestroy();
		Log.d("lifecycle","onDestroy invoked");
	}
}
