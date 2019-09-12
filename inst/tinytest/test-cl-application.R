# Test RestRserveApplication class

# Test empty object
a = RestRserveApplication$new()
expect_true(inherits(a$content_type, "character"))
expect_equal(a$content_type, "text/plain")
expect_true(inherits(a$HTTPError, "HTTPErrorFactory"))
expect_true(inherits(a$logger, "Logger"))
expect_true(inherits(a$.__enclos_env__$private$handlers, "environment"))
expect_equal(length(a$.__enclos_env__$private$handlers), 0L)
expect_true(inherits(a$.__enclos_env__$private$handlers_openapi_definitions, "environment"))
expect_equal(length(a$.__enclos_env__$private$handlers_openapi_definitions), 0L)
expect_true(inherits(a$.__enclos_env__$private$middleware, "environment"))
expect_equal(length(a$.__enclos_env__$private$middleware), 0L)
expect_true(inherits(a$.__enclos_env__$private$routes, "environment"))
expect_equal(length(a$.__enclos_env__$private$routes), 0L)
expect_equal(a$.__enclos_env__$private$supported_methods,
             c("GET", "HEAD", "POST", "PUT", "DELETE", "OPTIONS", "PATCH"))

# Test empty routes handling
a = RestRserveApplication$new()
rq = RestRserveRequest$new()
rs = RestRserveResponse$new()
expect_null(a$.__enclos_env__$private$match_handler(rq, rs))

# Test app with middleware
mw = RestRserveMiddleware$new(
  process_request = function(rq, rs) {},
  process_response = function(rq, rs) {}
)
a = RestRserveApplication$new(middleware = list(mw))
expect_equal(length(a$.__enclos_env__$private$middleware), 1L)
expect_equal(names(a$.__enclos_env__$private$middleware), c("1"))
expect_equal(a$.__enclos_env__$private$middleware[["1"]], mw)

# Test append_middleware method
a = RestRserveApplication$new()
mw = RestRserveMiddleware$new(
  process_request = function(rq, rs) {},
  process_response = function(rq, rs) {}
)
a$append_middleware(mw)
a$append_middleware(mw)
expect_equal(length(a$.__enclos_env__$private$middleware), 2L)
expect_equal(names(a$.__enclos_env__$private$middleware), c("1", "2"))
expect_equal(a$.__enclos_env__$private$middleware[["1"]], mw)

# Test add_route method
a = RestRserveApplication$new()
f1 = function(rq, rs) {1}
f2 = function(rq, rs) {2}
f3 = function(rq, rs) {3}
id1 = a$add_route("/", "GET", f1, "exact")
id2 = a$add_route("/test1", "GET", f2, "exact")
id3 = a$add_route("/test1", "POST", f3, "exact")
expect_equal(length(a$.__enclos_env__$private$handlers), 3L)
expect_equal(a$.__enclos_env__$private$handlers[[id1]], f1)
expect_equal(a$.__enclos_env__$private$handlers[[id2]], f2)
expect_equal(a$.__enclos_env__$private$handlers[[id3]], f3)

# Test add_get method
a = RestRserveApplication$new()
f1 = function(rq, rs) {1}
f2 = function(rq, rs) {2}
a$add_get("/test1", f1, "exact", add_head = FALSE)
a$add_get("/test2", f2, "exact")
expect_equal(length(a$.__enclos_env__$private$handlers), 3L)
expect_equal(a$.__enclos_env__$private$handlers[["1"]], f1)
expect_equal(a$.__enclos_env__$private$handlers[["2"]], f2) # head method
expect_equal(a$.__enclos_env__$private$handlers[["3"]], f2)

# Test add_post method
a = RestRserveApplication$new()
f1 = function(rq, rs) {1}
f2 = function(rq, rs) {2}
id1 = a$add_post("/test1", f1, "exact")
id2 = a$add_post("/test2", f2, "exact")
expect_equal(length(a$.__enclos_env__$private$handlers), 2L)
expect_equal(a$.__enclos_env__$private$handlers[[id1]], f1)
expect_equal(a$.__enclos_env__$private$handlers[[id2]], f2)

# Test error on duplicates routes
a = RestRserveApplication$new()
f = function(rq, rs) {1}
a$add_route("/", "GET", f, "exact")
expect_error(a$add_route("/", "GET", f, "exact"))
a$add_route("/prefix", "GET", f, match = "partial")
expect_error(a$add_route("/prefix", "GET", f, match = "partial"))
a$add_route("/regex/{var}", "GET", f, match = "regex")
expect_error(a$add_route("/regex/{var}", "GET", f, match = "regex"))

# est call_handler method
a = RestRserveApplication$new()
f = function(rq, rs) {rs$body = list(a = 1)}
rq = RestRserveRequest$new()
rs = RestRserveResponse$new()
a$.__enclos_env__$private$call_handler(f, rq, rs)
expect_equal(rs$body, list(a = 1))

# Test match_handler method
a = RestRserveApplication$new()
f1 = function(rq, rs) {1}
f2 = function(rq, rs) {2}
rq1 = RestRserveRequest$new(path = "/")
rq2 = RestRserveRequest$new(path = "/regex/value")
rs = RestRserveResponse$new()
id1 = a$add_route("/", "GET", f1, "exact")
id2 = a$add_route("/regex/{var}", "GET", f2, match = "regex")
r1 = a$.__enclos_env__$private$match_handler(rq1, rs)
r2 = a$.__enclos_env__$private$match_handler(rq2, rs)
expect_equal(r1, id1)
expect_equivalent(r2, id2)
expect_equal(attr(r2, "parameters_path"), list(var = "value"))

# Test process_request method
a = RestRserveApplication$new()
f = function(rq, rs) {rs$body = "text"}
a$add_route("/", "GET", f, "exact")
rq = RestRserveRequest$new(path = "/")
rs = RestRserveResponse$new()
r = a$process_request(rq)
expect_equal(r, list("text", "text/plain", character(0), 200L))

# Test endpoints method
a = RestRserveApplication$new()
f = function(rq, rs) {}
expect_equal(a$endpoints, list())
a$add_route("/", "GET", f, "exact")
a$add_route("/dir", "GET", f, "partial")
a$add_route("/post", "POST", f, "exact")
ep = list(
  "POST" = c("exact" = "/post"),
  "GET" = c("exact" = "/", "partial" = "/dir/")
)
expect_equal(a$endpoints, ep)