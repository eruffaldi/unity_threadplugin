
using UnityEngine;
using System.Runtime.InteropServices;

public class UseNative2 : MonoBehaviour {


	[DllImport("test1", EntryPoint = "TestSort")]
	public static extern void TestSort(int [] a, int length);
	
	[DllImport("test1", EntryPoint = "next")]
	public static extern int next();

	[DllImport("test1", EntryPoint = "start")]
	public static extern int start();

	[DllImport("test1", EntryPoint = "stop")]
	public static extern int stop();

	public int[] a;
	
	void Start() {
		a = new int[2];
		a [0] = 1;
		a [1] = 0;
		TestSort(a, a.Length);
		Debug.Log (a [0]);
		start ();
		Debug.Log ("start");
	}

	void OnDestroy() {
		stop ();
	}

	void Update() {
		Debug.Log (next ());
	}
}
