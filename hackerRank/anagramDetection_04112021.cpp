#include <string>

bool isAnagram(std::string test, std::string original){
  int arr[125] = { 0 };
  int arr2[125] = { 0 };

  for(auto i = 0; i < (int)test.size(); i++){
      if(test[i] < 97){
        arr[(int)test[i]+32]++;
      } else {
        arr[(int)test[i]]++;
      }
  }

  for(auto i = 0; i < (int)original.size(); i++){
      if(original[i] < 97){
        arr2[(int)original[i]+32]++;
      } else {
        arr2[(int)original[i]]++;
      }

  }

  bool ret = true;

  for(auto i = 0; i < 125; i++){
      if(arr[i] != arr2[i]){
          ret = false;
          break;
      }
  }

  return ret;
}