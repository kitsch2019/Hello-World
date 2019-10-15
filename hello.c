#include <stdio.h>
#include <curl/curl.h>

int main(void) {

	CURL* curl;
	CURLcode res;

	curl = curl_ easy_ init();
	if (curl){
		curl_ easy_ setopt(curl, CURLOPT_ _URL, "http://myip. ipip. net/"); 
		res = curl_ easy_ perform(curl); 
		if (res != CURLE_OK)
			fprintf(stderr, "curl_ easy_ perform()	failed:%s\n",
					curl_ easy_ strerror(res)); 
		curl_ easy_ cleanup(curl);
	}
return0;
}
