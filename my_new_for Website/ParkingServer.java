import static spark.Spark.*;
import com.google.gson.Gson;
import java.util.HashMap;
import java.util.Map;

public class App {
    public static void main(String[] args) {
        port(4567);

        // Serve static files from the "public" directory
        staticFiles.externalLocation("public");

        // Simulated parking status logic
        get("/status", (req, res) -> {
            res.type("application/json");
            Map<String, String> status = new HashMap<>();
            long time = System.currentTimeMillis();
            status.put("status", time % 2 == 0 ? "OCCUPIED" : "FREE");
            return new Gson().toJson(status);
        });
    }
}