import java.nio.channels.ClosedChannelException
import akka.actor.ActorSystem
import io.netty.channel.Channel
import isc.FaviconException
import isc.annotations.{Param, ServiceMethod}
import isc.api.http.{HttpToXmlApiServer, HttpService, HttpApi}
import ru.dogma.netty.http.{FullHttpResponse, FullHttpRequest}

import java.util.{Calendar, Iterator}


object Server extends  App{

  MyServer.bind("127.0.0.1", 8080);
}

object MyApi extends HttpApi{

  override type ServiceBase = HttpService

  val services:ServiceMap = {
    case "myservice" => classOf[ ImageService ]
  }
}

object MyServer extends HttpToXmlApiServer{

  val api = MyApi

  val system = ActorSystem("test-system")

  override def handler_exception(ch: Channel, httpRequest:FullHttpRequest): PartialFunction[Throwable, Unit] = {

    case e:FaviconException => {
      writeError(ch, 500, e.getMessage)
    }

    case e:Throwable => {
      if( !e.isInstanceOf[ ClosedChannelException ]){
        writeError(ch, 500, e.getMessage)
      }
    }
  }

  def writeError(ch:Channel, errorCode:Int, errorMessage:String): Unit ={

    val response = <x status={errorCode.toString} msg={errorMessage} />

    val httpResponse = new FullHttpResponse().replaceContent(response.toString())

    writeAndClose(ch, httpResponse)
  }
}