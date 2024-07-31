import 'dart:ffi';
import 'package:ffi/ffi.dart' as ffi;

typedef OpenclTestCpp = Pointer<ffi.Utf8> Function();
typedef OpenclTest = Pointer<ffi.Utf8> Function();

typedef DeleteCpp = Void Function(Pointer<Void>);
typedef Delete = void Function(Pointer<Void>);

void main() {
  final lib = DynamicLibrary.open("libocltest.so");

  OpenclTest ocltest =
      lib.lookup<NativeFunction<OpenclTestCpp>>('test_opencl').asFunction();

  Delete deleteNative =
      lib.lookup<NativeFunction<DeleteCpp>>('delete_ptr').asFunction();

  final nativeStr = ocltest();
  print(nativeStr.toDartString());
  deleteNative(nativeStr as Pointer<Void>);
}
