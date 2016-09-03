题目是给两个json 输出两个的合并 合并的结果不包括两个json的intersection 写完了之后follow up了怎么improve 怎么test 
http://stackoverflow.com/questions/2403132/concat-multiple-jsonobjects

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.Map;
import com.google.gson.Gson;  
import com.google.gson.JsonArray;  
import com.google.gson.JsonElement;  
import com.google.gson.JsonObject;  
import com.google.gson.JsonParser;  

public class HelloWorld {
	public static JsonObject deepMerge(JsonObject source, JsonObject target) {
	    for (Map.Entry<String,JsonElement> sourceEntry : source.entrySet()) {
	        String key = sourceEntry.getKey();
	        JsonElement value = sourceEntry.getValue();
	        if (!target.has(key)) {	            
	            if (!value.isJsonNull()) { 
	            	target.add(key, value);
	            }
	        } else {
	            if (!value.isJsonNull()) {
	                if (value.isJsonObject()) {	             
	                    deepMerge(value.getAsJsonObject(), target.get(key).getAsJsonObject());
	                } else {
	                    target.add(key,value);
	                }
	            } else {
	                target.remove(key);
	            }
	        }
	    }
	    return target;
	}
	
   public static void main(String[] args) {
	    JsonParser parser = new JsonParser();
	    JsonObject a = null;
	    JsonObject b = null;
	    a = parser.parse("{offer: {issue1: null, issue2: null}, accept: true, reject: null}").getAsJsonObject();
	    b = parser.parse("{offer: {issue2: value2}, reject: false}").getAsJsonObject();
	    System.out.println(deepMerge(a,b));
	    // prints:
	    // {"offer":{},"accept":true}
	    a = parser.parse("{offer: {issue1: value1}, accept: true, reject: null}").getAsJsonObject();
	    b = parser.parse("{offer: {issue2: value2}, reject: false}").getAsJsonObject();
	    System.out.println(deepMerge(a,b));
	    // prints:
	    // {"offer":{"issue2":"value2","issue1":"value1"},"accept":true}
   }
}


